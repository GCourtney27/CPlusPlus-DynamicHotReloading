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
}

void ScriptableActor::MyCustomMethod()
{
	// Do fancy stuff here
}

const char* ScriptableActor::GetName()
{
	return "ScriptableActor";
}

extern "C" ScriptableActor* Factory()
{
	return new ScriptableActor;
}
