#pragma once

namespace app::player
{
	class alignas(16) PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener
	{
		Player* pPlayer{};
		BlackboardStatus* pBlackboardStatus{};
	};
}