#pragma once
#include "../../interfaces/interfaces.h"

// https://www.piday.org/million/
// one milion int PI
#define PI 3.1415926535

namespace render
{
	void Setup();

	void DrawLine(std::int32_t from_x, std::int32_t from_y, std::int32_t to_x, std::int32_t to_y, CColor color);
	void DrawTextWChar(std::int32_t x, std::int32_t y, unsigned long font, const wchar_t* string, bool text_centered, CColor colour);
	void DrawTextString(std::int32_t x, std::int32_t y, unsigned long font, std::string string, bool text_centered, CColor colour);
	void DrawRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color);
	void DrawFilledRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color);
	void DrawOutline(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color);
	void DrawCircle(std::int32_t x, std::int32_t y, std::int32_t radius, std::int32_t segments, CColor color);
	CVector GetTextSize(unsigned long font, std::string text);
	void DrawFade(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color1, CColor color2, bool horizontal);

	namespace fonts 
	{
		inline unsigned long normal = 0;		// default font used through the cheat
		inline unsigned long mediumSize = 0;		// medium size
		inline unsigned long noShadow = 0;		// no shadow
		inline unsigned long playernameFont = 0;	// wchar support
		inline unsigned long weaponIcons = 0;
	};
}