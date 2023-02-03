#pragma once
#include "../interfaces/interfaces.h"
#include "../utility/imgui/imgui.h"
#include "../utility/imgui/imgui_impl_dx9.h"
#include "../utility/imgui/imgui_impl_win32.h"

enum MenuTabs : int
{
	TAB_HOME,
	TAB_RAGEBOT,
	TAB_LEGITBOT,
	TAB_ANTIAIM,
	TAB_WORLD,
	TAB_SCREEN,
	TAB_MISC,
	TAB_SKINS,
	TAB_CONFIG,
	TAB_SCRIPTS
};

namespace menuData
{
	bool Open();
	void Press();
	void SetupColors();

	inline constexpr std::uint8_t GUI_KEY = VK_INSERT;
	inline bool guiOpen = false;
}

namespace ImGui
{
	bool Tab(std::string name);
	void HelpMarker(std::string msg);
}

namespace visuals
{
	void Menu();
	void Watermark();
}