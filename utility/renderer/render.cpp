#include "render.h"

void render::Setup()
{
	render::fonts::normal = interfaces::surface->FontCreate();
	render::fonts::mediumSize = interfaces::surface->FontCreate();
	render::fonts::noShadow = interfaces::surface->FontCreate();
	render::fonts::playernameFont = interfaces::surface->FontCreate();
	render::fonts::weaponIcons = interfaces::surface->FontCreate();

	interfaces::surface->SetFontGlyphSet(render::fonts::normal, "Tahoma", 12, 500, 0, 0, FONT_FLAG_DROPSHADOW);
	interfaces::surface->SetFontGlyphSet(render::fonts::mediumSize, "Tahoma", 14, 500, 0, 0, FONT_FLAG_DROPSHADOW);
	interfaces::surface->SetFontGlyphSet(render::fonts::noShadow, "Tahoma", 12, 500, 0, 0, 0);
	interfaces::surface->SetFontGlyphSet(render::fonts::playernameFont, "Lucida Console", 12, 500, 0, 0, 0);
	interfaces::surface->SetFontGlyphSet(render::fonts::weaponIcons, "Counter-Strike", 28, 300, 0, 0, FONT_FLAG_OUTLINE | FONT_FLAG_DROPSHADOW); // 0x210 ??????
}

void render::DrawLine(std::int32_t from_x, std::int32_t from_y, std::int32_t to_x, std::int32_t to_y, CColor color)
{
	interfaces::surface->DrawSetColor(color.r, color.g, color.b, color.a);
	interfaces::surface->DrawLine(from_x, from_y, to_x, to_x);
}

void render::DrawTextWChar(std::int32_t x, std::int32_t y, unsigned long font, const wchar_t* string, bool text_centered, CColor colour)
{
	int width, height;
	interfaces::surface->GetTextSize(font, string, width, height);

	interfaces::surface->DrawSetTextColor(colour.r, colour.g, colour.b, colour.a);
	interfaces::surface->DrawSetTextFont(font);

	if (text_centered) 
		interfaces::surface->DrawSetTextPos(x - (width / 2), y);
	else 
		interfaces::surface->DrawSetTextPos(x, y);

	interfaces::surface->DrawPrintText(string, wcslen(string));
}

void render::DrawTextString(std::int32_t x, std::int32_t y, unsigned long font, std::string string, bool text_centered, CColor colour)
{
	const auto convertedText = std::wstring(string.begin(), string.end());

	int width, height;
	interfaces::surface->GetTextSize(font, convertedText.c_str(), width, height);

	interfaces::surface->DrawSetTextColor(colour.r, colour.g, colour.b, colour.a);
	interfaces::surface->DrawSetTextFont(font);

	if (text_centered)
		interfaces::surface->DrawSetTextPos(x - (width / 2), y);
	else 
		interfaces::surface->DrawSetTextPos(x, y);

	interfaces::surface->DrawPrintText(convertedText.c_str(), wcslen(convertedText.c_str()));
}

void render::DrawRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color)
{
	interfaces::surface->DrawSetColor(color.r, color.g, color.b, color.a);
	interfaces::surface->DrawOutlinedRect(x, y, width, height);
}

void render::DrawFilledRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color)
{
	interfaces::surface->DrawSetColor(color.r, color.g, color.b, color.a);
	interfaces::surface->DrawFilledRect(x, y, width, height);
}

void render::DrawOutline(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color)
{
	interfaces::surface->DrawSetColor(color.r, color.g, color.b, color.a);
	interfaces::surface->DrawOutlinedRect(x, y, width, height);
}

void render::DrawCircle(std::int32_t x, std::int32_t y, std::int32_t radius, std::int32_t segments, CColor color)
{
	float step = PI * 2.0 / segments;
	for (float a = 0; a < (PI * 2.0); a += step)
	{
		float x1 = radius * cos(a) + x;
		float y1 = radius * sin(a) + y;
		float x2 = radius * cos(a + step) + x;
		float y2 = radius * sin(a + step) + y;

		interfaces::surface->DrawSetColor(color.r, color.g, color.b, color.a);
		interfaces::surface->DrawLine(x1, y1, x2, y2);
	}
}

CVector render::GetTextSize(unsigned long font, std::string text)
{
	std::wstring a(text.begin(), text.end());
	const wchar_t* wstr = a.c_str();
	static int w, h;

	interfaces::surface->GetTextSize(font, wstr, w, h);
	return { static_cast<float>(w), static_cast<float>(h) };
}

void render::DrawFade(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, CColor color1, CColor color2, bool horizontal)
{
	//interfaces::surface->DrawSetColor(color1.r, color1.g, color1.b, color1.a);
	//interfaces::surface->DrawFilledRectFade(x, y, x + width, y + height, 255, 0, horizontal);
	//interfaces::surface->DrawSetColor(color2.r, color2.g, color2.b, color2.a);
	//interfaces::surface->DrawFilledRectFade(x, y, x + width, y + height, 0, 255, horizontal);
}
