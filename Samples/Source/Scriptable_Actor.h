#pragma once
#include "Actor_Base.h"

class __declspec(dllexport) ScriptableActor : public ActorBase
{
public:
	ScriptableActor();
	~ScriptableActor();

	void OnStart() override;
	void OnUpdate(float DeltaMs) override;

	const char* GetName() override;

	void MyCustomMethod();

	ScriptableActor* Factory();


private:
	int m_Var1;
	float m_Var2;
};
