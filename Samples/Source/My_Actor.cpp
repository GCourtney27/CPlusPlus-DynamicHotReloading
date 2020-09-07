#include "My_Actor.h"

#include <stdio.h>

MyActor::MyActor()
	: ActorBase("MyScriptedActor")
{

}

MyActor::~MyActor()
{

}

void MyActor::OnStart()
{
	printf("Starting method from MyActor\n");
}

void MyActor::OnUpdate(float DeltaMs)
{
	printf("Updating method from MyActor\n");
	//printf("Better Change!\n");
}

void MyActor::MyCustomMethod()
{
	printf("Hello from custom method");
}

const char* MyActor::GetName()
{
	return "MyActor";
}

MyActor* MyActor::Factory()
{
	return new MyActor;
}
