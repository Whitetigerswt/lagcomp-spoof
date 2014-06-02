#include <Windows.h>

void WINAPI Load();
HMODULE hMod = NULL;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hMod = hModule;
		if ( CreateThread( 0, 0, (LPTHREAD_START_ROUTINE)Load, NULL, 0, 0) == NULL ) {
			ExitProcess(GetLastError());
			return FALSE; 
		}
		break;
	}
	return TRUE;
}

void WINAPI Load() {
	DWORD sampdll = (DWORD)GetModuleHandle("samp.dll");
	DWORD oldProt = NULL;
	VirtualProtect((void*)(sampdll + 0x22C799), 6, PAGE_EXECUTE_READWRITE, &oldProt);
	memcpy((void*)(sampdll + 0x22C799), "\x90\x90\x90\x90\x90\x90", 6);
	DWORD oldProt2 = NULL;
	VirtualProtect((void*)(sampdll + 0x22C799), 6, oldProt, &oldProt2);
	FreeLibraryAndExitThread(hMod, 0);
}