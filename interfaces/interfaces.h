#pragma once
#include <d3d9.h>
#include "../csgo sdk/sdk.h"

namespace interfaces
{
	void Setup();

	inline IBaseClientDLL* client = nullptr;
	inline IClientModeShared* clientMode = nullptr;
	inline IGlobalVars* globals = nullptr;
	inline IVPanel* panel = nullptr;
	inline ISurface* surface = nullptr;
	inline IVEngineClient* engine = nullptr;
	inline void* keyValuesSystem = nullptr;
	inline IClientEntityList* entityList = nullptr;
	inline IDirect3DDevice9* device = nullptr;
}