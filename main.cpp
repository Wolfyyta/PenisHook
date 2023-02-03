#include <Windows.h>
#include <thread>
#include "globals.h"
#include "hooks/hooks.h"
#include "interfaces/interfaces.h"
#include "utility/netvars/netvars.h"
#include "utility/renderer/render.h"

DWORD WINAPI MainThread(PVOID instance)
{
	Beep(200, 200);

	while (!GetModuleHandle("serverbrowser.dll"))
		std::this_thread::sleep_for(std::chrono::seconds(15));

	// get windows username
	char buff[MAX_PATH];
	GetEnvironmentVariableA("USERNAME", buff, MAX_PATH);
	globals.username = std::string(buff);

	try
	{
		interfaces::Setup();
		netvars::Setup();
		render::Setup();
		hooks::Setup();
	}
	catch (std::exception& ex)
	{
		MessageBox(0, ex.what(), "cheat", 0);
		FreeLibraryAndExitThread(static_cast<HMODULE>(instance), EXIT_SUCCESS);
	}

	while (!globals.unload)
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	hooks::Unload();

	FreeLibraryAndExitThread(static_cast<HMODULE>(instance), EXIT_SUCCESS);
	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain(HMODULE instance, DWORD reasonForCall, LPVOID reserved)
{
	DisableThreadLibraryCalls(instance);

	switch (reasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		const HANDLE handle = CreateThread(0, 0, MainThread, instance, 0, 0);
		if (handle)
			CloseHandle(handle);

		break;
	}

	return TRUE;
}