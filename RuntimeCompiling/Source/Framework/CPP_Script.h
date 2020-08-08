#pragma once

#include "Framework/Script_Symbol_Refs.h"

namespace Framework {

	class ScriptEngine;
	class ::ActorBase;
	
	class CPPScript
	{
	public:
		CPPScript(ScriptEngine* pScriptEngine);

		bool Init();
		void Run();
		void Destroy();

		inline void SetLibraryHandle(void* pHandle) { m_pLibraryHandle = pHandle; }
		void* GetLibraryHandle() const { return m_pLibraryHandle; }

	private:
		ScriptEngine* m_pScriptEngine = nullptr;
		OutActorInVoidMethod_t m_ActorFactory;

		void* m_pLibraryHandle = nullptr;
		ActorBase* m_pAliasActor = nullptr;

		OutVoidInVoidMethod_t m_CustomVoidMethod;

	};

}
