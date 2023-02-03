#pragma once
#include <string>
#include "csgo sdk/cvector.h"

class CBaseEntity;
class CUserCmd;
struct Globals
{
public:
	std::string username = "";
	bool unload = false;
	CBaseEntity* local = nullptr;
	bool sendPacket = false;
	CUserCmd* cmd = nullptr;
	CVector cameraAngle;
};
inline Globals globals;