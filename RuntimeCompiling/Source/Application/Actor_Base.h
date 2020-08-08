#pragma once

/*
	To make associations inside the dll a little easier, we can have an aliase class that is the
	parent to the class defined in the dll. 
	
	In 'Scripts/Scriptable_Actor.h' you can see we make this associatiation and override the methods
	that are pure virtual in here.

	// TODO; do they have to be pure virtual?
	// TODO: can the dll call the ase class? ie Actor::Onupdate() from ScriptableActor::OnUpdate()?
*/

class ActorBase
{
public:
	ActorBase(const char* Name)
	: m_Name(Name) {}
	~ActorBase() {}

	virtual void OnStart() = 0;
	virtual void OnUpdate(float DeltaMs) = 0;
	
	virtual const char* GetName() = 0;

protected:
	const char* m_Name;
};
