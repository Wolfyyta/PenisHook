#pragma once
#include "../interfaces/interfaces.h"
#include "../utility/minhook/minhook.h"

namespace hooks
{
	void Setup();
	void Unload();

	// thanks nullhooks
	__forceinline unsigned int GetVirtual(void* ptr, unsigned int index) 
	{ 
		return static_cast<unsigned int>((*static_cast<int**>(ptr))[index]);
	}

	namespace PaintTraverse
	{
		inline int index = 41;
		using fn = void(__thiscall*)(IVPanel*, unsigned int, bool, bool);
		inline fn og;
		void __stdcall Hook(unsigned int panel, bool forceRepaint, bool allowForce);
	}

	namespace FrameStageNotify
	{
		inline int index = 37;
		using fn = void(__thiscall*)(void*, EClientFrameStage);
		inline fn og;
		void __stdcall Hook(EClientFrameStage stage);
	}

	namespace CreateMove
	{
		inline int index = 24;
		using fn = bool(__stdcall*)(float, CUserCmd*);
		inline fn og;
		bool Hook(float inputFrametime, CUserCmd* cmd, bool& sendPacket);
		void Proxy();
	}

	namespace OverrideView 
	{
		inline int index = 18;
		using fn = void(__thiscall*)(void*, CViewSetup*);
		inline fn og;
		void __fastcall Hook(uintptr_t ecx, uintptr_t edx, CViewSetup* setup);
	}

	namespace EndScene
	{
		inline int index = 42;
		using fn = long(__thiscall*)(void*, IDirect3DDevice9*);
		inline fn og;
		long __stdcall Hook(IDirect3DDevice9* device);
	}

	namespace Reset
	{
		inline int index = 16;
		using fn = HRESULT(__thiscall*)(void*, IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
		inline fn og;
		HRESULT __stdcall Hook(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params);
	}

	namespace WNDProc
	{
		static LRESULT __stdcall Hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	}
}