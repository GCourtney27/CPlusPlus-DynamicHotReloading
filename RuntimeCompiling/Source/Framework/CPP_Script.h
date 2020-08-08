#pragma once

#include "Framework/Script_Symbol_FnPtrs.h"

namespace Framework {

	class ScriptEngine;
	class ::ActorBase;
	
	class CPPScript
	{
	public:
		CPPScript(ScriptEngine* pScriptEngine);
		~CPPScript() {}

		bool Init();
		void Run();
		void Destroy();

		inline void SetModuleName(const char* Name) { m_ModuleName = Name; }
		inline const char* GetModuleName() { return m_ModuleName; }
		inline void SetLibraryHandle(void* pHandle) { m_pLibraryHandle = pHandle; }
		void* GetLibraryHandle() const { return m_pLibraryHandle; }

	private:
		ScriptEngine* m_pScriptEngine = nullptr;
		const char* m_ModuleName = nullptr;

		void* m_pLibraryHandle = nullptr;
		ActorBase* m_pAliasActor = nullptr;
		OutActorInVoidMethod_t m_ActorFactory;
		
	};

}
