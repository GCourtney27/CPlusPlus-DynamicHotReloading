#pragma once

#include <vector>

namespace Framework {

	class CPPScript;

	class ScriptEngine
	{
	public:
		ScriptEngine();
		~ScriptEngine();

		static ScriptEngine& Get() { return *s_Instance; }

		void LoadCPPFromFile(const char* Filename);
		void RunScripts();
		void CloseApp() { m_Running = false; }
		void Cleanup();

		void* GetMethodHandleFromDllByString(void* pLibraryhandle, const char* MethodSymbolName);
		void CloseLibraryHandle(void* pLibraryhandle);
	private:
		void GetLastDlfcnError();
	private:
		bool m_Running = true;
		
		std::vector<CPPScript*> m_Scripts;
		const char* m_ScriptDirectory = "Scripts/";

	private:
		static ScriptEngine* s_Instance;

	};

}
