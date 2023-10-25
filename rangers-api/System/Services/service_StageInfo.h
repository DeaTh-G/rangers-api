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
			eAttributeFlags_Cyber = 0x01,
			eAttributeFlags_Minigame = 0x02,
			eAttributeFlags_Hacking = 0x03,
			eAttributeFlags_LastBoss = 0x04,
			eAttributeFlags_MasterTrial = 0x05,
			eAttributeFlags_Tutorial = 0x06,
			eAttributeFlags_Navmesh = 0x08,
			eAttributeFlags_HeightField = 0x09,
			eAttributeFlags_PointCloud = 0x0A,
			eAttributeFlags_Autosave = 0x0B,
			eAttributeFlags_Diving = 0x0D,
			eAttributeFlags_SideStep = 0x0E,
			eAttributeFlags_Athletic = 0x0F,
			eAttributeFlags_Boarding = 0x10,
			eAttributeFlags_Drift = 0x11,
			eAttributeFlags_SideView = 0x12,
			eAttributeFlags_Lava = 0x13,
			eAttributeFlags_Sonic = 0x14,
			eAttributeFlags_Tails = 0x15,
			eAttributeFlags_Amy = 0x16,
			eAttributeFlags_Knuckles = 0x17,
			eAttributeFlags_BattleRush = 0x18,
			eAttributeFlags_BossRush = 0x19,
			eAttributeFlags_Extra = 0x1A,
			eAttributeFlags_DeleteFallDeadCollision = 0x1B,
			eAttributeFlags_DeleteAirWallCollision = 0x1C,
			eAttributeFlags_DeleteGrindRail = 0x1D,
			eAttributeFlags_ChangeNewCollision = 0x1E,
			eAttributeFlags_RestrictDebris = 0x1F,
			eAttributeFlags_SpecialParryEffect = 0x20
		};

		enum ECyberModeFlags
		{
			eCyberModeFlags_LowGravity = 0x01,
			eCyberModeFlags_TimeExtend = 0x02,
			eCyberModeFlags_SpeedScale = 0x03,
			eCyberModeFlags_Nitro = 0x04,
			eCyberModeFlags_MaxSpeedChallenge = 0x05
		};

		enum EMissionFlags
		{
			eMissionFlags_Goal = 0x01,
			eMissionFlags_Rank = 0x02,
			eMissionFlags_Ring = 0x04,
			eMissionFlags_RedRing = 0x05,
			eMissionFlags_NumberRing = 0x06,
			eMissionFlags_SilverMoonRing = 0x07,
			eMissionFlags_HideGoal = 0x08,
			eMissionFlags_ShadowTails = 0x09,
			eMissionFlags_Mine = 0x0A,
			eMissionFlags_Animal = 0x0B
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