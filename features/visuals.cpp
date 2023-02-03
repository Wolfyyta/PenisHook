#include "visuals.h"
#include "../globals.h"
#include "../utility/utilities.h"
#include "../utility/renderer/render.h"
#include "../utility/configs/config.h"

bool menuData::Open()
{
	return guiOpen;
}

void menuData::Press()
{
	guiOpen = !guiOpen;
}

void menuData::SetupColors()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_Separator] = style.Colors[ImGuiCol_Border];
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	style.GrabRounding = style.FrameRounding = 2.3f;
	style.WindowTitleAlign = { 0.5, 0.5 };
}

bool ImGui::Tab(std::string name)
{
	static bool ret = false;

	ImGui::Selectable(name.c_str(), &ret);

	return ret;
}

void ImGui::HelpMarker(std::string msg)
{
	ImGui::SameLine();

	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);

		ImGui::TextUnformatted(msg.c_str());

		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void visuals::Menu()
{
	if (!menuData::Open())
		return;

	ImGui::StyleColorsDark();
	menuData::SetupColors();

	static int tab = 0;

	ImGui::SetNextWindowSize({777, 666});
	ImGui::Begin(std::string("penishook").c_str(), &menuData::guiOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
	{
		auto menuWidth = ImGui::GetWindowWidth();
		auto menuHeight = ImGui::GetWindowHeight();

		ImGui::BeginChild("###tabs", ImVec2(770, 35), true);
		{
			ImGui::PushStyleColor(ImGuiCol_Button, {0, 0, 0, 0});
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 0, 0, 0, 0 });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0, 0, 0, 0 });
			{
				if (ImGui::Button("ragebot"))
					tab = 1;

				ImGui::SameLine();

				if (ImGui::Button("legitbot"))
					tab = 2;

				ImGui::SameLine();

				if (ImGui::Button("antiaim"))
					tab = 3;

				ImGui::SameLine();

				if (ImGui::Button("world"))
					tab = 4;

				ImGui::SameLine();

				if (ImGui::Button("screen"))
					tab = 5;

				ImGui::SameLine();

				if (ImGui::Button("miscellaneous"))
					tab = 6;

				ImGui::SameLine();

				if (ImGui::Button("skinchanger"))
					tab = 7;

				ImGui::SameLine();

				if (ImGui::Button("configs"))
					tab = 8;

				ImGui::SameLine();

				if (ImGui::Button("scripts"))
					tab = 9;

				ImGui::SameLine();

				if (ImGui::Button("unload"))
					globals.unload = true;
			}
			ImGui::PopStyleColor(3);
		}
		ImGui::EndChild();

		switch (tab)
		{
		case TAB_MISC:

			ImGui::BeginGroup();
			{
				//ImGui::BeginChild("###main", ImVec2(menuWidth - 7, menuHeight - 40), true);
				{
					ImGui::Text("main");
					//ImGui::Separator();

					ImGui::Checkbox("bunnyhop", cfg.bunnyHop); ImGui::HelpMarker("automaticly bunnyhops when you hold the jump button");
				}
				//ImGui::EndChild();
			}
			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginGroup();
			{
				ImGui::Text("others");
				//ImGui::Separator();

				ImGui::Checkbox("watermark", cfg.watermark);
				ImGui::Checkbox("disable keyboard", cfg.disableKeyboardInputWhenMenuIsOn); ImGui::HelpMarker("disable keyboard input when menu is showing");
			}
			ImGui::EndGroup();
			break;

		case TAB_WORLD:

			ImGui::BeginGroup();
			{
				//ImGui::BeginChild("###main", ImVec2(menuWidth - 7, menuHeight - 40), true);
				{
					ImGui::Text("main");
					//ImGui::Separator();

					ImGui::Checkbox("remove scope", cfg.removeScope); ImGui::HelpMarker("removes the scope outline, redrawing the lines");
				}
				//ImGui::EndChild();
			}
			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginGroup();
			{
				ImGui::Text("others");
				//ImGui::Separator();

				
			}
			ImGui::EndGroup();
			break;

		case TAB_CONFIG:
			ImGui::BeginGroup();
			{
				//ImGui::BeginChild("###main", ImVec2(menuWidth - 7, menuHeight - 40), true);
				{
					ImGui::Text("configs");

					// todo: slot system (1, 2, 3, 4, 5, 6...10)
					if (ImGui::Button("save config"))// ImGui::HelpMarker("saves the current cheat state at (penishook.ini)");
					{
						configSystem::Save();
						//MessageBox(0, std::string("config saved ( " + configSystem::configName + " )").c_str(), "penishook", 0);
					}

					if (ImGui::Button("load config"))// ImGui::HelpMarker("loads the last saved cheat state from (penishook.ini)");
					{
						configSystem::Load();
						//MessageBox(0, std::string("config loaded ( " + configSystem::configName + " )").c_str(), "penishook", 0);
					}
				}
				//ImGui::EndChild();
			}
			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginGroup();
			{

			}
			ImGui::EndGroup();

			break;
		}
	}
	ImGui::End();
}

void visuals::Watermark()
{
	if (!cfg.watermark)
		return;

	std::string text = " < penishook / ";
	text += utils::GetUsername();
	text += " > ";

	CVector size = render::GetTextSize(render::fonts::normal, text);

	render::DrawFilledRect(2, 10, size.x + 4, size.y + 12, { 12, 12, 12, 200 });
	render::DrawFilledRect(0, 10, 2, size.y + 12, CColor::Red(255));
	render::DrawTextString(4, 10, render::fonts::normal, text, false, CColor::White(255));
}
