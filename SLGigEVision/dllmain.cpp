// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "SLGigEVision_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CSLGigEVisionModule _AtlModule;

char gBaseDir[MAX_PATH] = { 0 };

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	GetModuleFileNameA(hInstance, gBaseDir, _countof(gBaseDir));
	int pos = 0;
	for (int i = 0; i < MAX_PATH; i++) {
		if (0 == gBaseDir[i])  break;
		else if ('/' == gBaseDir[i])  pos = i;
		else if ('\\' == gBaseDir[i])  pos = i;
	}
	gBaseDir[pos + 1] = 0;
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(hInstance, dwReason, lpReserved))
		return FALSE;
#endif
	return _AtlModule.DllMain(dwReason, lpReserved);
}
