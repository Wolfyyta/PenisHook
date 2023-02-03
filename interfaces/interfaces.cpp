#include <Windows.h>
#include "interfaces.h"
#include "../utility/utilities.h"

template <typename Interface>
Interface* GetInterface(const char* moduleName, const char* interfaceName) noexcept
{
	const HINSTANCE handle = GetModuleHandle(moduleName);

	if (!handle)
		return nullptr;

	using CreateInterfaceFn = Interface * (__cdecl*)(const char*, int*);
	const CreateInterfaceFn createInterface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(handle, "CreateInterface"));

	return createInterface(interfaceName, nullptr);
}

void interfaces::Setup()
{
	client = GetInterface<IBaseClientDLL>("client.dll", "VClient018");
	clientMode = **reinterpret_cast<IClientModeShared***>((*reinterpret_cast<unsigned int**>(client))[10] + 5);
	globals = **reinterpret_cast<IGlobalVars***>((*reinterpret_cast<uintptr_t**>(client))[11] + 10);
	panel = GetInterface<IVPanel>("vgui2.dll", "VGUI_Panel009");
	surface = GetInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface031");
	engine = GetInterface<IVEngineClient>("engine.dll", "VEngineClient014");
	keyValuesSystem = reinterpret_cast<void* (__cdecl*)()>(GetProcAddress(GetModuleHandle("vstdlib.dll"), "KeyValuesSystem"))();
	entityList = GetInterface<IClientEntityList>("client.dll", "VClientEntityList003");
	device = **reinterpret_cast<IDirect3DDevice9***>(utils::PatternScan("shaderapidx9.dll", "A1 ? ? ? ? 50 8B 08 FF 51 0C") + 0x1);
}
