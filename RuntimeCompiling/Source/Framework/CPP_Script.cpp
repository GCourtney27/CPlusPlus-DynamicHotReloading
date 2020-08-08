#include "CPP_Script.h"

#include "Framework/Script_Engine.h"
#include "Application/Actor_Base.h"

namespace Framework {


	CPPScript::CPPScript(ScriptEngine* pScriptEngine)
		: m_pScriptEngine(pScriptEngine)
	{
	}

	bool CPPScript::Init()
	{
		// Get a reference to the object from the dll
		m_ActorFactory = (OutActorInVoidMethod_t)m_pScriptEngine->GetMethodHandleFromDllByString(m_pLibraryHandle, "Factory");
		// To call functions from the class you must have an alias class. We do that here.
		m_pAliasActor = m_ActorFactory();

		return true;
	}

	void CPPScript::Run()
	{
		// This could be an update method that gets called every frame
		// where you'd pass in the timestep.
		// Here we are just passing in a value to demonstrate.
		float DeltaMs = 0.0f;
		m_pAliasActor->OnUpdate(DeltaMs);
	}

	void CPPScript::Destroy()
	{
		m_pScriptEngine->CloseLibraryHandle(m_pLibraryHandle);
	}
}

