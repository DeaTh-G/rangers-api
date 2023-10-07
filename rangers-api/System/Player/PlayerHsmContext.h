#pragma once

namespace app::player
{
	class Player;

	class alignas(8) PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener
	{
	private:

	public:
		Player* pPlayer{};
		BlackboardStatus* pBlackboardStatus{};
		INSERT_PADDING(88) {};

		Player* GetPlayer() const
		{
			return pPlayer;
		}
	};
}