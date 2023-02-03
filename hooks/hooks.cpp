#include "hooks.h"
#include "../globals.h"
#include <algorithm>
#include <intrin.h>
#include "../utility/renderer/render.h"

#include "../utility/imgui/imgui.h"
#include "../utility/imgui/imgui_impl_dx9.h"
#include "../utility/imgui/imgui_impl_win32.h"

#include "../features/misc.h"
#include "../features/visuals.h"
#include "../utility/configs/config.h"

void __stdcall hooks::PaintTraverse::Hook(unsigned int panel, bool forceRepaint, bool allowForce)
{
	auto panelToDraw = hash::RunTime(interfaces::panel->GetName(panel));

	switch (panelToDraw)
	{
	case hash::CompileTime("MatSystemTopPanel"):
		if (globals.local && globals.local->IsAlive() && globals.local->IsScoped() && cfg.removeScope)
		{
			int w, h;
			interfaces::engine->GetScreenSize(w, h);

			const int mid_x = w / 2;
			const int mid_y = h / 2;

			interfaces::surface->DrawSetColor(CColor::Black(240));
			interfaces::surface->DrawLine(0, mid_y, w, mid_y);	// X
			interfaces::surface->DrawLine(mid_x, 0, mid_x, h);	// Y
		}

		visuals::Watermark();

		break;

	case hash::CompileTime("HudZoom"):
		if (cfg.removeScope)
			return;

		break;

	case hash::CompileTime("FocusOverlayPanel"):
		if (cfg.disableKeyboardInputWhenMenuIsOn)
			interfaces::panel->SetKeyboard(panel, menuData::Open());

		interfaces::panel->SetMouse(panel, menuData::Open());

		break;
	}

	og(interfaces::panel, panel, forceRepaint, allowForce);
}

void __stdcall hooks::FrameStageNotify::Hook(EClientFrameStage stage)
{
	if (!globals.local)
		globals.local = interfaces::entityList->GetEntityFromIndex(interfaces::engine->GetLocalPlayerIndex());

	switch (stage)
	{
	case FRAME_RENDER_START:

		break;
	}

	og(interfaces::client, stage);
}

bool hooks::CreateMove::Hook(float inputFrametime, CUserCmd* cmd, bool& sendPacket)
{
	og(inputFrametime, cmd);

	if (!cmd || !cmd->commandNumber)
		return og(inputFrametime, cmd);

	if (!globals.local)
		return og(inputFrametime, cmd);

	misc::Bunnyhop(cmd);

	globals.cmd = cmd;
	globals.sendPacket = sendPacket;

	cmd->forwardMove = std::clamp(cmd->forwardMove, -450.0f, 450.0f);
	cmd->sideMove = std::clamp(cmd->sideMove, -450.0f, 450.0f);
	cmd->upMove = std::clamp(cmd->upMove, -320.0f, 320.0f);

	return false;
}

void __declspec(naked) hooks::CreateMove::Proxy()
{
	__asm 
	{
		push ebp
		mov  ebp, esp
		push ebx
		push esp
		push[ebp + 0xC]	
		push[ebp + 0x8]	
		//movss xmm0, [ebp + 0x8] 
		call hooks::CreateMove::Hook
		add esp, 0xC
		pop ebx	
		mov esp, ebp
		pop ebp
		ret 0x8	
	}
}

void __fastcall hooks::OverrideView::Hook(uintptr_t ecx, uintptr_t edx, CViewSetup* setup)
{
	if (!setup)
		og(interfaces::clientMode, setup);

	// if (scopeFov && scoped) setup.fov = scopeFov;
	// if (fov && !scoped) setup.fov = fov;
	//if (globals.local && globals.local->IsAlive())
	//	setup->fov = 180; // 80 - original

	globals.cameraAngle = setup->origin;
	og(interfaces::clientMode, setup);
}

long __stdcall hooks::EndScene::Hook(IDirect3DDevice9* device)
{
	static const auto retAddr = _ReturnAddress();

	if (_ReturnAddress() == retAddr)
		return og(device, device);

	static bool dxSetup = false;
	if (!dxSetup)
	{
		ImGui::CreateContext();

		ImGui_ImplWin32_Init(FindWindowA("Valve001", nullptr));
		ImGui_ImplDX9_Init(device);

		// here we can initialize textures, fonts, etc for imgui use only

		dxSetup = true;
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	{
		visuals::Menu();
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return og(device, device);
}

HRESULT __stdcall hooks::Reset::Hook(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	const auto result = og(device, device, params);
	ImGui_ImplDX9_CreateDeviceObjects();

	return result;
}

WNDPROC oldWindow = reinterpret_cast<WNDPROC>(SetWindowLongPtr(FindWindowA("Valve001", nullptr), GWL_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::WNDProc::Hook)));
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall hooks::WNDProc::Hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (GetAsyncKeyState(menuData::GUI_KEY) & 1)
		menuData::Press();

	if (menuData::Open() && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return 1L;

	return CallWindowProc(oldWindow, hWnd, uMsg, wParam, lParam);
}

void hooks::Setup()
{
	MH_Initialize();

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::panel, PaintTraverse::index)), 
		&PaintTraverse::Hook, reinterpret_cast<void**>(&PaintTraverse::og)
	);

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::client, FrameStageNotify::index)),
		&FrameStageNotify::Hook, reinterpret_cast<void**>(&FrameStageNotify::og)
	);

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::clientMode, CreateMove::index)),
		&CreateMove::Proxy, reinterpret_cast<void**>(&CreateMove::og)
	);

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::clientMode, OverrideView::index)),
		&OverrideView::Hook, reinterpret_cast<void**>(&OverrideView::og)
	);

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::device, EndScene::index)),
		&EndScene::Hook, reinterpret_cast<void**>(&EndScene::og)
	);

	MH_CreateHook(reinterpret_cast<void*>(GetVirtual(interfaces::device, Reset::index)),
		&Reset::Hook, reinterpret_cast<void**>(&Reset::og)
	);

	MH_EnableHook(MH_ALL_HOOKS);
}

void hooks::Unload()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}
