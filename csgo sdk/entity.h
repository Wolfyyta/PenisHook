#pragma once
#include "../utility/utilities.h"
#include "cmatrix.h"
#include "cclientclass.h"
#include "cvector.h"
#include "../utility/netvars/netvars.h"

enum EFlags : std::int32_t
{
	FL_ONGROUND = (1 << 0),
	FL_DUCKING = (1 << 1),
	FL_ANIMDUCKING = (1 << 2),
	FL_WATERJUMP = (1 << 3),
	FL_ONTRAIN = (1 << 4),
	FL_INRAIN = (1 << 5),
	FL_FROZEN = (1 << 6),
	FL_ATCONTROLS = (1 << 7),
	FL_CLIENT = (1 << 8),
	FL_FAKECLIENT = (1 << 9),
	FL_INWATER = (1 << 10),
	FL_FLY = (1 << 11),
	FL_SWIM = (1 << 12),
	FL_CONVEYOR = (1 << 13),
	FL_NPC = (1 << 14),
	FL_GODMODE = (1 << 15),
	FL_NOTARGET = (1 << 16),
	FL_AIMTARGET = (1 << 17),
	FL_PARTIALGROUND = (1 << 18),
	FL_STATICPROP = (1 << 19),
	FL_GRAPHED = (1 << 20),
	FL_GRENADE = (1 << 21),
	FL_STEPMOVEMENT = (1 << 22),
	FL_DONTTOUCH = (1 << 23),
	FL_BASEVELOCITY = (1 << 24),
	FL_WORLDBRUSH = (1 << 25),
	FL_OBJECT = (1 << 26),
	FL_KILLME = (1 << 27),
	FL_ONFIRE = (1 << 28),
	FL_DISSOLVING = (1 << 29),
	FL_TRANSRAGDOLL = (1 << 30),
	FL_UNBLOCKABLE_BY_PLAYER = (1 << 31)
};

enum EWeaponType : int
{
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL = 1,
	WEAPONTYPE_SUBMACHINEGUN = 2,
	WEAPONTYPE_RIFLE = 3,
	WEAPONTYPE_SHOTGUN = 4,
	WEAPONTYPE_SNIPER = 5,
	WEAPONTYPE_MACHINEGUN = 6,
	WEAPONTYPE_C4 = 7,
	WEAPONTYPE_PLACEHOLDER = 8,
	WEAPONTYPE_GRENADE = 9,
	WEAPONTYPE_HEALTHSHOT = 11,
	WEAPONTYPE_FISTS = 12,
	WEAPONTYPE_BREACHCHARGE = 13,
	WEAPONTYPE_BUMPMINE = 14,
	WEAPONTYPE_TABLET = 15,
	WEAPONTYPE_MELEE = 16
};

class CBaseEntity;
class IClientEntityList
{
public:
	constexpr CBaseEntity* GetEntityFromIndex(const std::int32_t index) noexcept
	{
		return utils::CallVFunc<CBaseEntity*>(this, 3, index);
	}
};

class CBaseCombatWeapon;
class CBaseEntity
{
public:
	NETVAR(GetFlags, "CBasePlayer->m_fFlags", std::int32_t);
	NETVAR(IsScoped, "CCSPlayer->m_bIsScoped", bool);
	NETVAR(IsDefusing, "CCSPlayer->m_bIsDefusing", bool);
	NETVAR(HasGunGameImmunity, "CCSPlayer->m_bGunGameImmunity", bool);

	constexpr bool SetupBones(CMatrix3x4* out, std::int32_t max, std::int32_t mask, float currentTime) noexcept
	{
		return utils::CallVFunc<bool>(this + 0x4, 13, out, max, mask, currentTime);
	}

	constexpr CClientClass* GetClientClass() noexcept
	{
		return utils::CallVFunc<CClientClass*>(this + 0x8, 2);
	}

	constexpr bool IsDormant() noexcept
	{
		return utils::CallVFunc<bool>(this + 0x8, 9);
	}

	constexpr std::int32_t GetIndex() noexcept
	{
		return utils::CallVFunc<std::int32_t>(this + 0x8, 10);
	}

	constexpr const CVector& GetAbsOrigin() noexcept
	{
		return utils::CallVFunc<const CVector&>(this, 10);
	}

	constexpr std::int32_t GetTeam() noexcept
	{
		return utils::CallVFunc<std::int32_t>(this, 88);
	}

	constexpr std::int32_t GetHealth() noexcept
	{
		return utils::CallVFunc<std::int32_t>(this, 122);
	}

	constexpr bool IsAlive() noexcept
	{
		return utils::CallVFunc<bool>(this, 156);
	}

	constexpr bool IsPlayer() noexcept
	{
		return utils::CallVFunc<bool>(this, 158);
	}

	constexpr bool IsWeapon() noexcept
	{
		return utils::CallVFunc<bool>(this, 166);
	}

	constexpr CBaseCombatWeapon* GetActiveWeapon() noexcept
	{
		return utils::CallVFunc<CBaseCombatWeapon*>(this, 268);
	}

	constexpr void GetEyePosition(CVector& eyePosition) noexcept
	{
		utils::CallVFunc<void>(this, 285, std::ref(eyePosition));
	}

	constexpr CBaseEntity* GetObserverTarget() noexcept
	{
		return utils::CallVFunc<CBaseEntity*>(this, 295);
	}

	constexpr void GetAimPunch(CVector& aimPunch) noexcept
	{
		utils::CallVFunc<void>(this, 346, std::ref(aimPunch));
	}
};

class CBaseCombatWeapon
{
public:
	NETVAR(GetAmmo, "CBaseCombatWeapon->m_iClip1", int);

	constexpr int GetWeaponType() noexcept
	{
		return utils::CallVFunc<int>(this, 455);
	}
};