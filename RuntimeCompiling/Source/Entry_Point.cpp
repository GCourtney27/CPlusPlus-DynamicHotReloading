#include "stdafx.h"

#include "Framework/Script_Engine.h"
#include "Framework/Script_Symbol_FnPtrs.h"
#include "Application/Actor_Base.h"
#include <Windows.h>
#include <strsafe.h>
#include <cassert>

/*
	For debugging it is recomended you use dependency walker to view the symbols of the compiled dll.
*/

void TestDlfcn();
void ManualLoad();
LPCTSTR GetLastWindowsError();

#define USE_MSVC 0

int main()
{
#if defined _MSC_VER && USE_MSVC
	ManualLoad();
#else
	TestDlfcn(); // NOTE: Platform must be set to Win32 for this to work.
#endif

	return 0;
}

void ManualLoad()
{
	// Load the dll.
	HMODULE hModule;
	hModule = LoadLibraryEx(L"msvc.dll", NULL, NULL);
	OutActorInVoidMethod_t ScriptableActorFactry;
	// Assemble the symbol that will be looked-up in the dll.
	char SymbolBuffer[128];
	const char* ActorClassName = "ScriptableActor";
	sprintf_s(SymbolBuffer, "?Factory@%s@@QEAAPEAV1@XZ", ActorClassName);

	if (hModule != NULL)
	{
		// Create the alias actor so we can call the underlying methods.
		ScriptableActorFactry = (OutActorInVoidMethod_t)GetProcAddress(hModule, SymbolBuffer); // Symbols are decorated
		ActorBase* pActor = ScriptableActorFactry();
		// Call a generic method;
		pActor->OnStart();
		// Call a method with parameter. 
		float DeltaTime = 0.25f;
		pActor->OnUpdate(DeltaTime);
		// Get a value from the class.
		const char* Name = pActor->GetName();
		printf("Actor name: %s", Name);

		LPCTSTR Error = GetLastWindowsError();
		
		// Free the resources.
		FreeLibrary(hModule);
		delete pActor;
	}

}

void TestDlfcn()
{
	Framework::ScriptEngine Engine;
	Engine.LoadCPPFromFile("Scriptable_Actor");
	Engine.RunScripts();

	printf("Application closed...");
}

LPCTSTR GetLastWindowsError()
{
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = ::GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	lpDisplayBuf = (LPVOID)::LocalAlloc(LMEM_ZEROINIT, (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)"") + 40) * sizeof(TCHAR));
	StringCchPrintf(
		(LPTSTR)lpDisplayBuf,
		::LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		"", dw, lpMsgBuf
	);
	return (LPCTSTR)lpDisplayBuf;
}
