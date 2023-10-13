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
		enum Attributes
		{
			Cyber = 0x01,
			Minigame = 0x02,
			Hacking = 0x03,
			LastBoss = 0x04,
			MasterTrial = 0x05,
			Tutorial = 0x06,
			Navmesh = 0x08,
			HeightField = 0x09,
			PointCloud = 0x0A,
			Autosave = 0x0B,
			Diving = 0x0D,
			SideStep = 0x0E,
			Athletic = 0x0F,
			Boarding = 0x10,
			Drift = 0x11,
			SideView = 0x12,
			Lava = 0x13,
			Sonic = 0x14,
			Tails = 0x15,
			Amy = 0x16,
			Knuckles = 0x17,
			BattleRush = 0x18,
			BossRush = 0x19,
			Extra = 0x1A,
			DeleteFallDeadCollision = 0x1B,
			DeleteAirWallCollision = 0x1C,
			DeleteGrindRail = 0x1D,
			ChangeNewCollision = 0x1E,
			RestrictDebris = 0x1F,
			SpecialParryEffect = 0x20
		};

		enum Missions
		{
			Goal = 0x01,
			Rank = 0x02,
			Ring = 0x04,
			RedRing = 0x05,
			NumberRing = 0x06,
			SilverMoonRing = 0x07,
			HideGoal = 0x08,
			ShadowTails = 0x09,
			Mine = 0x0A,
			Animal = 0x0B
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