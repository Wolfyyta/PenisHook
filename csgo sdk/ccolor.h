#pragma once
#include <cstdint>

class CColor
{
public:
	constexpr CColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255) :
		r(r), g(g), b(b), a(a) { }

	// https://www.rapidtables.com/web/color/RGB_Color.html
	static CColor Red(std::uint8_t a = 255) { return { 255, 0, 0, a }; }
	static CColor Green(std::uint8_t a = 255) { return { 0, 255, 0, a }; }
	static CColor Blue(std::uint8_t a = 255) { return { 0, 0, 255, a }; }
	static CColor Black(std::uint8_t a = 255) { return { 0, 0, 0, a }; }
	static CColor White(std::uint8_t a = 255) { return { 255, 255, 255, a }; }
	static CColor Purple(std::uint8_t a = 255) { return { 128, 0, 128, a }; }
	static CColor Pink(std::uint8_t a = 255) { return { 255, 0, 255, a }; }
	static CColor DarkGrey(std::uint8_t a = 255) { return { 32, 32, 32, a }; }
	static CColor SlateGrey(std::uint8_t a = 255) { return { 112, 128, 144, a }; }

	std::uint8_t r{ }, g{ }, b{ }, a{ };
};