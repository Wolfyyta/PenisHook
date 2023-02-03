#pragma once
#include "../utility/utilities.h"

class IVPanel
{
public:
	const char* GetName(std::uint32_t panel)
	{
		return utils::CallVFunc<const char*>(this, 36, panel);
	}

	void SetKeyboard(unsigned int panel, bool state)
	{
		using original_fn = void(__thiscall*)(void*, unsigned int, bool);
		return (*(original_fn**)this)[31](this, panel, state);
	}

	void SetMouse(unsigned int panel, bool state)
	{
		using original_fn = void(__thiscall*)(void*, unsigned int, bool);
		return (*(original_fn**)this)[32](this, panel, state);
	}
};