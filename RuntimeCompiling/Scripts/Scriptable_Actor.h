#pragma once
#include "../Source/Application/Actor_Base.h"

class ScriptableActor : public ActorBase
{
public:
	ScriptableActor();
	virtual ~ScriptableActor();

	virtual void OnStart() override;
	virtual void OnUpdate(float DeltaMs) override;

	virtual const char* GetName() override;

	void MyCustomMethod();

private:
	int m_Var1;
	float m_Var2;
};
