#include <stdafx.h>

#include "Script_Engine.h"

#include "CPP_Script.h"
#include "Application/Actor_Base.h"

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
		// NOTE: It doesnt matter how you compile the dll, it could come from a visual studio project
		//		 it just needs to be loaded by the 'dlopen' command below
		//		 here we are just using MinGW as a compiler for the dll for convenience.
		//::system(ConsoleCommad.c_str());
		CPPScript* pScript = new CPPScript(this);

		char DllOutputLocation[128];
		//::sprintf_s(DllOutputLocation, "Scripts/CompiledBinaries/%s-Assembly.dll", Filename);
		//::sprintf_s(DllOutputLocation, "Scripts/CompiledBinaries/msvc.dll");
		::sprintf_s(DllOutputLocation, "msvc.dll");

		// Open the library so we can use it to make method associations in the CPPScript's
		void* pHandle = ::dlopen(DllOutputLocation, RTLD_LAZY);
		if (!pHandle) GetLastDlfcnError();

		pScript->SetLibraryHandle(pHandle);
		pScript->SetModuleName(Filename);
		pScript->Init();

		m_Scripts.push_back(pScript);
	}

	void ScriptEngine::Recompile()
	{
		m_Recompiling = true;

		m_Scripts[0]->Destroy();
		delete m_Scripts[0];
		m_Scripts.clear();
		LoadCPPFromFile("Scriptable_Actor");

		//size_t NumScripts = m_Scripts.size();
		//for (uint32_t i = 0; i < NumScripts; ++i) {

		//	const char* ModuleName = m_Scripts[i]->GetModuleName();
		//	m_Scripts[i]->Destroy();
		//	delete m_Scripts[i];
		//	//m_Scripts.clear();
		//	LoadCPPFromFile(ModuleName);
		//}

		m_Recompiling = false;
	}

	static void GetUserInput()
	{
		while (true) {

			printf("Press \"%c\" to close and \"%c\" to recompile.\n", 'q', 'c');
			char Option;
			std::cin >> Option;

			if (Option == 'q') {
				ScriptEngine::Get().CloseApp();
				break;
			}
			else if (Option == 'c') {
				ScriptEngine::Get().Recompile();
			}
		}
	}

	void ScriptEngine::RunScripts()
	{
		using namespace std::literals::chrono_literals;
		std::thread CheckAppQuitThread(GetUserInput);

		// Simple game loop simulation
		while (m_Running) {

			if (m_Recompiling) {
				continue;
			}

			for (auto& pScript : m_Scripts) {

				printf("Module-%s: ", pScript->GetModuleName());
				pScript->Run();
			}

			std::this_thread::sleep_for(2s);
		}

		CheckAppQuitThread.join();
	}

	void ScriptEngine::Cleanup()
	{
		for (auto& Script : m_Scripts) {
			Script->Destroy();
		}
		m_Scripts.clear();
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
		char* ErrorMessage = ::dlerror();
		std::stringstream ss;
		ss << "dlfcn load error: " << ErrorMessage;
		std::cout << ss.str() << "\n";
		
		throw std::runtime_error(ss.str());
	}

}
