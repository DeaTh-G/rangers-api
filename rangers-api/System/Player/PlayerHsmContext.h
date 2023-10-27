#pragma once

namespace app::player
{
	class Player;
	class GOCPlayerHsm;

	class alignas(8) PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener
	{
	public:
		Player* pPlayer{};
		BlackboardStatus* pBlackboardStatus{};
		INSERT_PADDING(8);
		GOCPlayerHsm* pGOCPlayerHsm;
		INSERT_PADDING(56);
		void* pOutOfControlTimerList; // app::player::PlayerHsmContext::OutOfControlTimerList
		void* pDamagedObjects;        // app::player::PlayerHsmContext::DamagedObjects

		Player* GetPlayer() const
		{
			return pPlayer;
		}

		bool GetCombatFlag(BlackboardStatus::ECombatFlags in_flag)
		{
			return pBlackboardStatus->GetCombatFlag(in_flag);
		}

		void SetCombatFlag(BlackboardStatus::ECombatFlags in_flag, bool in_isEnable)
		{
			pBlackboardStatus->SetCombatFlag(in_flag, in_isEnable);
		}

		bool GetStateFlag(BlackboardStatus::EStateFlags in_flag)
		{
			return pBlackboardStatus->GetStateFlag(in_flag);
		}

		void SetStateFlag(BlackboardStatus::EStateFlags in_flag, bool in_isEnable)
		{
			pBlackboardStatus->SetStateFlag(in_flag, in_isEnable);
		}

		bool GetWorldFlag(BlackboardStatus::EWorldFlags in_flag)
		{
			return pBlackboardStatus->GetWorldFlag(in_flag);
		}

		void SetWorldFlag(BlackboardStatus::EWorldFlags in_flag, bool in_isEnable)
		{
			pBlackboardStatus->SetWorldFlag(in_flag, in_isEnable);
		}
	};
}