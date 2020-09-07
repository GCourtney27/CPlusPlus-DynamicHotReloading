#include "stdafx.h"

#include "Framework/Script_Engine.h"
#include "Framework/Script_Symbol_FnPtrs.h"
#include "Application/Actor_Base.h"
#include <Windows.h>
#include <strsafe.h>
#include <cassert>

void TestDlfcn();
void TestManualLoad();
LPCTSTR GetLastWindowsError();

int main()
{
	TestManualLoad();
	//TestDlfcn();

	return 0;
}

void TestManualLoad()
{
	HMODULE hModule;
	
	hModule = LoadLibraryEx(L"msvc.dll", NULL, NULL);
	if (hModule != NULL)
	{
		//OutVoidInVoidMethod_t FactoryMethod = (OutVoidInVoidMethod_t)GetProcAddress(hModule, "?PrintMethod@@YAXXZ"); // Symbols are decorated
		OutActorInVoidMethod_t FactoryMethod = (OutActorInVoidMethod_t)GetProcAddress(hModule, "Factory"); // Symbols are decorated
		LPCTSTR Error = GetLastWindowsError();
		//FactoryMethod();
		ActorBase* pActor = FactoryMethod();
		pActor->OnStart();
		
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
