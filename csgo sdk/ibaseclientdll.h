#pragma once
#include "../utility/utilities.h"
#include "cclientclass.h"

class IBaseClientDLL
{
public:
	CClientClass* GetAllClasses()
	{
		return utils::CallVFunc<CClientClass*>(this, 8);
	}
};