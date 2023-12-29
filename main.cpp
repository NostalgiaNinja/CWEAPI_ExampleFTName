#include "pch.h"
#include "cwe_api.h"

extern "C"
{
	//registering data functions.
	void (*RegisterDataFunc)(void* ptr);
	
	//Create a cstring variable
	char TestName[12] = "testname";


	void CWELoad(CWE_REGAPI* cwe_api)
	{
		cwe_api->RegisterFoName(TestName);
	}

	__declspec(dllexport) void Init()
	{
		HMODULE h = GetModuleHandle(L"CWE");

		RegisterDataFunc = (void (*)(void* ptr))GetProcAddress(h, "RegisterDataFunc");
		RegisterDataFunc(CWELoad);
	}
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}