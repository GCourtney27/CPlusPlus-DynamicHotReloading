#include <stdafx.h>

#include "Script_Engine.h"

#include "CPP_Script.h"

#include "dlfcn.h"
#include "dlfcn.c"


namespace Framework {

	ScriptEngine* ScriptEngine::s_Instance = nullptr;

	ScriptEngine::ScriptEngine()
	{
		assert(!s_Instance);
		s_Instance = this;
	}

	ScriptEngine::~ScriptEngine()
	{
		Cleanup();
	}

	void ScriptEngine::LoadCPPFromFile(const char* Filename)
	{
		// Compile the source code file using the command line
		std::string ConsoleCommad;
		ConsoleCommad += "C:/MinGW/bin/g++ -shared ";
		ConsoleCommad += m_ScriptDirectory;
		ConsoleCommad += Filename;
		ConsoleCommad += ".cpp -o Scripts/CompiledBinaries/";
		ConsoleCommad += Filename;
		ConsoleCommad += "-Assembly.dll";

		// When submitting commands through system() it will look for files
		// relative to the .vcxproj while in visual studio
		system(ConsoleCommad.c_str());
		CPPScript* pScript = new CPPScript(this);

		char DllOutputLocation[128];
		sprintf_s(DllOutputLocation, "Scripts/CompiledBinaries/%s-Assembly.dll", Filename);
		// Open the library so we can use it to make method associations in the CPPScript's
		void* pHandle = dlopen(DllOutputLocation, RTLD_LAZY);
		if (!pHandle) GetLastDlfcnError();

		pScript->SetLibraryHandle(pHandle);
		pScript->Init();

		m_Scripts.push_back(pScript);
	}

	static void CheckAppQuit()
	{
		printf("Press \"%c\" to close and \"%c\" to recompile.", 'q', 'c');
		char Option;
		std::cin >> Option;

		if (Option == 'q') {
			ScriptEngine::Get().CloseApp();
		}
		else if (Option == 'c') {
			// TODO Recompile
		}
	}

	void ScriptEngine::RunScripts()
	{
		using namespace std::literals::chrono_literals;
		std::thread CheckAppQuitThread(CheckAppQuit);

		// Simple game loop simulation
		while (m_Running) {

			for (auto& Script : m_Scripts) {

				Script->Run();
			}
			
			std::this_thread::sleep_for(1s);
		}

		CheckAppQuitThread.join();
	}

	void ScriptEngine::Cleanup()
	{
		for (auto& Script : m_Scripts) {
			Script->Destroy();
		}
	}

	void* ScriptEngine::GetMethodHandleFromDllByString(void* pLibraryhandle, const char* MethodSymbolName)
	{
		void* MethodHandle = dlsym(pLibraryhandle, MethodSymbolName);
		if (!MethodHandle) {
			GetLastDlfcnError();
			return nullptr;
		}

		return MethodHandle;
	}

	void ScriptEngine::CloseLibraryHandle(void* pLibraryhandle)
	{
		dlclose(pLibraryhandle);
	}

	void ScriptEngine::GetLastDlfcnError()
	{
		char* ErrorMessage = dlerror();
		std::stringstream ss;
		ss << "dlfcn load error: " << ErrorMessage;
		std::cout << ss.str() << "\n";

		//throw std::runtime_error(ss.str());

	}

}
