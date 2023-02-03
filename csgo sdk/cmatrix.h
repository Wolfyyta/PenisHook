#pragma once

#include "cvector.h"

class CMatrix3x4
{
public:
	constexpr float* operator[](size_t index) noexcept
	{
		return data[index];
	}

	constexpr CVector Origin() noexcept
	{
		return { data[0][3], data[1][3], data[2][3] };
	}

	float data[3][4];
};

// Matrix 4x4 AKA ViewMatrix
class CMatrix4x4
{
public:
	float data[4][4];
};