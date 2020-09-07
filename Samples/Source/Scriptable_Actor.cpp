#include "Scriptable_Actor.h"

#include <stdio.h>

ScriptableActor::ScriptableActor()
	: ActorBase("MyScriptedActor")
{

}

ScriptableActor::~ScriptableActor()
{

}

void ScriptableActor::OnStart()
{
	printf("Starting method from ScriptableActor\n");
}

void ScriptableActor::OnUpdate(float DeltaMs)
{
	printf("Updating method from ScriptableActor\n");
	//printf("Better Change!\n");
}

void ScriptableActor::MyCustomMethod()
{
	printf("Hello from custom method");
}

const char* ScriptableActor::GetName()
{
	return "ScriptableActor";
}

extern "C" __declspec(dllexport) ScriptableActor* Factory()
{
	return new ScriptableActor;
}
