#pragma once

namespace app::player
{
	class alignas(16) BlackboardStatus : public BlackboardContent
	{
		inline static const char* ms_pBlackboardName = "BlackboardStatus";

	public:
		enum StateFlags
		{
			IsBoost = 0x00,
			IsAirBoost = 0x04,
			IsGrindJump = 0x06,
			IsGrind = 0x07,
			IsJump = 0x08,
			IsDoubleJump = 0x09,
			IsBounceJump = 0x0A,
			IsFall = 0x0B,
			IsStomp = 0x0C,
			IsDiving = 0x0D,
			IsDivingBoost = 0x0E,
			IsCyloop = 0x11,
			IsCyloopEnd = 0x12,
			IsDrift = 0x13,
			IsHoming = 0x17,
			IsParry = 0x18,
			IsWallClimb = 0x19,
			IsIdle = 0x1A,
			IsWallClimbIdle = 0x1C,
			IsBoarding = 0x1E,
			IsSpringJump = 0x21,
			IsPhantomRush = 0x26
		};
		
		enum CombatFlags
		{
			IsPerfectParry = 0x10
		};

		enum WorldFlags
		{
			IsDead = 0x01,
			IsDamagedOrRepelled = 0x02,
			IsOutOfControl = 0x07,
			IsAutoRun = 0x0A,
			IsCyberSpace = 0x1E,
			IsPowerBoost = 0x28,
			IsAirTrick = 0x2A,
			IsHeightMapCollision = 0x37,
			IsNoClip = 0x38,
			IsBattle = 0x3A
		};
		
	public:
		INSERT_PADDING(4);
		bool IsSuper;
		int64_t CombatFlags;
		INSERT_PADDING(8);
		int64_t StateFlags;
		int64_t WorldFlags;
		INSERT_PADDING(300);

		size_t GetNameHash() override
		{
			return csl::ut::StringMapOperation::hash(ms_pBlackboardName);
		}

		static const char* GetBlackboardName()
		{
			return ms_pBlackboardName;
		}
	};
}