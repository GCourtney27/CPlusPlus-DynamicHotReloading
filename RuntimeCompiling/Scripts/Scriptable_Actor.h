#pragma once
#include "../Source/Application/Actor_Base.h"

class ScriptableActor : public ActorBase
{
public:
	ScriptableActor();
	~ScriptableActor();

	void OnStart() override;
	void OnUpdate(float DeltaMs) override;

	const char* GetName() override;

	void MyCustomMethod();

private:
	int m_Var1;
	float m_Var2;
};
