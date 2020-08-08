#include "stdafx.h"

#include "Framework/Script_Engine.h"

int main()
{
	Framework::ScriptEngine Engine;
	Engine.LoadCPPFromFile("Scriptable_Actor");
	Engine.RunScripts();

	printf("Application closed...");
	return 0;
}
