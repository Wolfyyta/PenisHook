#pragma once
#include "../utility/utilities.h"
#include "cvector.h"
#include "cmatrix.h"

enum EClientFrameStage : int
{
	FRAME_UNDEFINED = -1,
	FRAME_START,
	// a network packet is being recieved
	FRAME_NET_UPDATE_START,
	// data has been received and we are going to start calling postdataupdate
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	// data has been received and called postdataupdate on all data recipients
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	// received all packets, we can now do interpolation, prediction, etc
	FRAME_NET_UPDATE_END,
	// start rendering the scene
	FRAME_RENDER_START,
	// finished rendering the scene
	FRAME_RENDER_END,
	FRAME_NET_FULL_FRAME_UPDATE_ON_REMOVE
};

struct PlayerInfo_t
{
	std::uint64_t	ullVersion = 0ULL;
	union
	{
		std::uint64_t ullXuid;
		struct
		{
			std::uint32_t nXuidLow;
			std::uint32_t nXuidHigh;
		};
	};

	char			name[128];
	int				userID;
	char			steamID[33];
	std::uint32_t	friendsID;
	char			friendsName[128];
	bool			fakePlayer;
	bool			isHLTV;
	unsigned long	customFiles[4];
	std::uint8_t	filesDownloaded;
};

struct AudioState_t
{
	CVector			vecOrigin;
	CVector			angAngles;
	bool			bIsUnderwater;
};

class IVEngineClient
{
public:
	constexpr void GetScreenSize(std::int32_t& width, std::int32_t& height) noexcept
	{
		utils::CallVFunc<void>(this, 5, std::ref(width), std::ref(height));
	}

	constexpr std::int32_t GetLocalPlayerIndex() noexcept
	{
		return utils::CallVFunc<std::int32_t>(this, 12);
	}

	constexpr void GetViewAngles(const CVector& angView) noexcept
	{
		utils::CallVFunc<void>(this, 18, std::ref(angView));
	}

	constexpr void SetViewAngles(const CVector& viewAngles) noexcept
	{
		utils::CallVFunc<void, const CVector&>(this, 19, viewAngles);
	}

	constexpr bool IsInGame() noexcept
	{
		return utils::CallVFunc<bool>(this, 26);
	}

	constexpr const CMatrix4x4& WorldToScreenMatrix() noexcept
	{
		return utils::CallVFunc<const CMatrix4x4&>(this, 37);
	}

	constexpr void* GetBSPTreeQuery() noexcept
	{
		return utils::CallVFunc<void*>(this, 43);
	}

	constexpr bool GetPlayerInfo(int nEntityIndex, PlayerInfo_t* pInfo) noexcept
	{
		return utils::CallVFunc<bool>(this, 8, nEntityIndex, pInfo);
	}

	constexpr bool IsConsoleVisible() noexcept
	{
		return utils::CallVFunc<bool>(this, 11);
	}

	constexpr bool IsDrawingLoadingImage() noexcept
	{
		return utils::CallVFunc<bool>(this, 28);
	}

	constexpr void ClientCmdUnrestricted(const char* szCmdString, bool bFromConsoleOrKeybind = false) noexcept
	{
		utils::CallVFunc<void>(this, 114, szCmdString, bFromConsoleOrKeybind);
	}

	constexpr bool IsVoiceRecording() noexcept
	{
		return utils::CallVFunc<bool>(this, 224);
	}

	constexpr const char* GetProductVersionString()noexcept
	{ 
		return utils::CallVFunc<const char*>(this, 105);
	}
};