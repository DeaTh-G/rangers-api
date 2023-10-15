#pragma once

namespace app::level
{
	class StageData;

	class StageInfo : public hh::game::GameService, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "StageInfo";

	public:
		csl::ut::ObjectMoveArray<StageData*> Stages;

		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};

	struct RankTimes
	{
	public:
		int32_t S, A, B, C;

		RankTimes(int32_t in_s, int32_t in_a, int32_t in_b, int32_t in_c)
		{
			S = in_s;
			A = in_a;
			B = in_b;
			C = in_c;
		}
	};

	class StageData : public hh::fnd::ReferencedObject
	{
	public:
		enum EAttributeFlags
		{
			EAttributeFlags_Cyber = 0x01,
			EAttributeFlags_Minigame = 0x02,
			EAttributeFlags_Hacking = 0x03,
			EAttributeFlags_LastBoss = 0x04,
			EAttributeFlags_MasterTrial = 0x05,
			EAttributeFlags_Tutorial = 0x06,
			EAttributeFlags_Navmesh = 0x08,
			EAttributeFlags_HeightField = 0x09,
			EAttributeFlags_PointCloud = 0x0A,
			EAttributeFlags_Autosave = 0x0B,
			EAttributeFlags_Diving = 0x0D,
			EAttributeFlags_SideStep = 0x0E,
			EAttributeFlags_Athletic = 0x0F,
			EAttributeFlags_Boarding = 0x10,
			EAttributeFlags_Drift = 0x11,
			EAttributeFlags_SideView = 0x12,
			EAttributeFlags_Lava = 0x13,
			EAttributeFlags_Sonic = 0x14,
			EAttributeFlags_Tails = 0x15,
			EAttributeFlags_Amy = 0x16,
			EAttributeFlags_Knuckles = 0x17,
			EAttributeFlags_BattleRush = 0x18,
			EAttributeFlags_BossRush = 0x19,
			EAttributeFlags_Extra = 0x1A,
			EAttributeFlags_DeleteFallDeadCollision = 0x1B,
			EAttributeFlags_DeleteAirWallCollision = 0x1C,
			EAttributeFlags_DeleteGrindRail = 0x1D,
			EAttributeFlags_ChangeNewCollision = 0x1E,
			EAttributeFlags_RestrictDebris = 0x1F,
			EAttributeFlags_SpecialParryEffect = 0x20
		};

		enum ECyberModeFlags
		{
			ECyberModeFlags_LowGravity = 0x01,
			ECyberModeFlags_TimeExtend = 0x02,
			ECyberModeFlags_SpeedScale = 0x03,
			ECyberModeFlags_Nitro = 0x04,
			ECyberModeFlags_MaxSpeedChallenge = 0x05
		};

		enum EMissionFlags
		{
			EMissionFlags_Goal = 0x01,
			EMissionFlags_Rank = 0x02,
			EMissionFlags_Ring = 0x04,
			EMissionFlags_RedRing = 0x05,
			EMissionFlags_NumberRing = 0x06,
			EMissionFlags_SilverMoonRing = 0x07,
			EMissionFlags_HideGoal = 0x08,
			EMissionFlags_ShadowTails = 0x09,
			EMissionFlags_Mine = 0x0A,
			EMissionFlags_Animal = 0x0B
		};

	public:
		csl::ut::MoveArray<uint8_t> Name;
		INSERT_PADDING(24); // csl::ut::MoveArray<T>
		csl::ut::MoveArray<uint8_t> SceneParamName;
		INSERT_PADDING(24); // csl::ut::MoveArray<T>
		csl::ut::MoveArray<uint8_t> Location;
		csl::ut::MoveArray<uint8_t> CyberName;
		int32_t StageIndex;
		int32_t CyberStageIndex;
		int32_t WorldIndex;
		int32_t DefaultSceneParamIndex;
		int64_t AttributeFlags;
		int64_t MissionFlags;
		csl::ut::ObjectMoveArray<uint8_t> StaticSectors;
		csl::ut::ObjectMoveArray<uint8_t> DynamicSectors;
		INSERT_PADDING(4);
		float TimeLimit;
		float DeadHeight;
		float NoiseTime;
		INSERT_PADDING(12);
		int32_t RingMissionThreshold;
		INSERT_PADDING(4);
		RankTimes Ranks;
		RankTimes RanksVeryHard;
		RankTimes RanksChallenge;
		RankTimes RanksChallengeAll;
		INSERT_PADDING(4);
	};
}