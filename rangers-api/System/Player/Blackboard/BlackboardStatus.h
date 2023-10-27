#pragma once

namespace app::player
{
	class alignas(16) BlackboardStatus : public BlackboardContent
	{
		inline static const char* ms_pBlackboardName = "BlackboardStatus";

	public:
		enum EStateFlags
		{
			eStateFlags_IsBoost = 0x00,
			eStateFlags_IsAirBoost = 0x04,
			eStateFlags_IsGrindJump = 0x06,
			eStateFlags_IsGrind = 0x07,
			eStateFlags_IsJump = 0x08,
			eStateFlags_IsDoubleJump = 0x09,
			eStateFlags_IsBounceJump = 0x0A,
			eStateFlags_IsFall = 0x0B,
			eStateFlags_IsStomp = 0x0C,
			eStateFlags_IsDiving = 0x0D,
			eStateFlags_IsDivingBoost = 0x0E,
			eStateFlags_IsCyloop = 0x11,
			eStateFlags_IsCyloopEnd = 0x12,
			eStateFlags_IsDrift = 0x13,
			eStateFlags_IsHoming = 0x17,
			eStateFlags_IsParry = 0x18,
			eStateFlags_IsWallClimb = 0x19,
			eStateFlags_IsIdle = 0x1A,
			eStateFlags_IsWallClimbIdle = 0x1C,
			eStateFlags_IsBoarding = 0x1E,
			eStateFlags_IsSpringJump = 0x21,
			eStateFlags_IsPhantomRush = 0x26
		};
		
		enum ECombatFlags
		{
			eCombatFlags_IsPerfectParry = 0x10,
			eCombatFlags_IsCycloneKick = 0x2A,
			eCombatFlags_IsSonicBoom = 0x2D,
			eCombatFlags_IsWildRush = 0x2E,
			eCombatFlags_IsLoopKick = 0x2F,
			eCombatFlags_IsSpinSlash = 0x30,
			eCombatFlags_IsStompAttack = 0x31,
			eCombatFlags_IsHomingShot = 0x33,
			eCombatFlags_IsCrossSlash = 0x34
		};

		enum EWorldFlags
		{
			eWorldFlags_IsDead = 0x01,
			eWorldFlags_IsDamagedOrRepelled = 0x02,
			eWorldFlags_IsOutOfControl = 0x07,
			eWorldFlags_IsAutoRun = 0x0A,
			eWorldFlags_IsCyberSpace = 0x1E,
			eWorldFlags_IsPowerBoost = 0x28,
			eWorldFlags_IsAirTrick = 0x2A,
			eWorldFlags_IsHeightMapCollision = 0x37,
			eWorldFlags_IsNoClip = 0x38,
			eWorldFlags_IsBattle = 0x3A
		};
		
	public:
		INSERT_PADDING(4);
		bool IsSuper;
		csl::ut::Bitset<uint64_t> CombatFlags[2]{};
		csl::ut::Bitset<uint64_t> StateFlags;
		csl::ut::Bitset<uint64_t> WorldFlags[2]{};
		INSERT_PADDING(410);

		size_t GetNameHash() override
		{
			return csl::ut::StringMapOperation::hash(ms_pBlackboardName);
		}

		static const char* GetBlackboardName()
		{
			return ms_pBlackboardName;
		}

		bool GetCombatFlag(ECombatFlags in_flag)
		{
			return CombatFlags[in_flag >> 6].test(in_flag & 0x3F);
		}

		void SetCombatFlag(ECombatFlags in_flag, bool in_isEnable)
		{
			CombatFlags[in_flag >> 6].set(in_flag & 0x3F);
		}

		bool GetStateFlag(EStateFlags in_flag)
		{
			return StateFlags.test(in_flag);
		}

		void SetStateFlag(EStateFlags in_flag, bool in_isEnable)
		{
			StateFlags.set(in_flag);
		}

		bool GetWorldFlag(EWorldFlags in_flag)
		{
			return WorldFlags[in_flag >> 6].test(in_flag & 0x3F);
		}

		void SetWorldFlag(EWorldFlags in_flag, bool in_isEnable)
		{
			WorldFlags[in_flag >> 6].set(in_flag & 0x3F);
		}
	};
}