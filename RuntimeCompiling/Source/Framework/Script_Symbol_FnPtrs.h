#pragma once

class ActorBase;

/*
	Description:
		Defines the function pointers that will be referenced from scripts.

	Info:
		Each symbol in the dll can be interpeted by its return type.
		Here, we list any methods we could encounter after loading the dll.
*/

// ---------------------
// void Return methods |
// ---------------------

 // void Method(void)
typedef void(*OutVoidInVoidMethod_t)(void);
// void Method(float)
typedef void(*OutVoidInFloatMethod_t)(float);

// ----------------------
// Value return methods  |
// ----------------------

// ActorBase Factory(void)
typedef ActorBase* (*OutActorInVoidMethod_t)();
// const char* Method(void)
typedef const char* (*OutCharInVoidMethod_t)();