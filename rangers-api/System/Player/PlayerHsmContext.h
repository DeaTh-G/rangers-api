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
	};
}