#pragma once
#include "Actor_Base.h"

class __declspec(dllexport) MyActor : public ActorBase
{
public:
	MyActor();
	~MyActor();

	void OnStart() override;
	void OnUpdate(float DeltaMs) override;

	const char* GetName() override;

	void MyCustomMethod();

	MyActor* Factory();


private:
	int m_Var1;
	float m_Var2;
};
