#pragma once
#include "../utility/utilities.h"
#include "ccolor.h"

enum EFontDrawType : std::int32_t
{
	FONT_DRAW_DEFAULT = 0,
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE
};

enum EFontFlag
{
	FONT_FLAG_NONE,
	FONT_FLAG_ITALIC = 0x001,
	FONT_FLAG_UNDERLINE = 0x002,
	FONT_FLAG_STRIKEOUT = 0x004,
	FONT_FLAG_SYMBOL = 0x008,
	FONT_FLAG_ANTIALIAS = 0x010,
	FONT_FLAG_GAUSSIANBLUR = 0x020,
	FONT_FLAG_ROTARY = 0x040,
	FONT_FLAG_DROPSHADOW = 0x080, 
	FONT_FLAG_ADDITIVE = 0x100,
	FONT_FLAG_OUTLINE = 0x200,
	FONT_FLAG_CUSTOM = 0x400,
	FONT_FLAG_BITMAP = 0x800,
};

class ISurface
{
public:
	void DrawSetColor(CColor color)
	{
		utils::CallVFunc<void>(this, 14, color);
	}

	void DrawLine(int x0, int y0, int x1, int y1)
	{
		utils::CallVFunc<void>(this, 19, x0, y0, x1, y1);
	}

	void DrawSetColor(int r, int g, int b, int a = 255)
	{
		utils::CallVFunc<void>(this, 15, r, g, b, a);
	}

	void DrawFilledRect(int x, int y, int xx, int yy)
	{
		utils::CallVFunc<void>(this, 16, x, y, xx, yy);
	}

	void DrawOutlinedRect(int x, int y, int xx, int yy)
	{
		utils::CallVFunc<void>(this, 18, x, y, xx, yy);
	}

	void DrawSetTextFont(unsigned long font)
	{
		utils::CallVFunc<void>(this, 23, font);
	}

	void DrawSetTextColor(CColor color)
	{
		utils::CallVFunc<void>(this, 24, color);
	}

	void DrawSetTextColor(int r, int g, int b, int a = 255)
	{
		utils::CallVFunc<void>(this, 25, r, g, b, a);
	}

	void DrawSetTextPos(int x, int y)
	{
		utils::CallVFunc<void>(this, 26, x, y);
	}

	void DrawPrintText(const wchar_t* text, int textLength, EFontDrawType drawType = FONT_DRAW_DEFAULT)
	{
		utils::CallVFunc<void>(this, 28, text, textLength, drawType);
	}

	void UnLockCursor()
	{
		return utils::CallVFunc<void>(this, 66);
	}

	void LockCursor()
	{
		return utils::CallVFunc<void>(this, 67);
	}

	unsigned long FontCreate()
	{
		return utils::CallVFunc<unsigned long>(this, 71);
	}

	bool SetFontGlyphSet(unsigned long hFont, const char* szWindowsFontName, int iTall, int iWeight, int iBlur, int nScanLines, int iFlags, int nRangeMin = 0, int nRangeMax = 0)
	{
		return utils::CallVFunc<bool>(this, 72, hFont, szWindowsFontName, iTall, iWeight, iBlur, nScanLines, iFlags, nRangeMin, nRangeMax);
	}

	void GetTextSize(unsigned long hFont, const wchar_t* wszText, int& iWide, int& iTall)
	{
		utils::CallVFunc<void>(this, 79, hFont, wszText, std::ref(iWide), std::ref(iTall));
	}

	void DrawOutlinedCircle(int x, int y, int iRadius, int nSegments)
	{
		utils::CallVFunc<void>(this, 103, x, y, iRadius, nSegments);
	}
};