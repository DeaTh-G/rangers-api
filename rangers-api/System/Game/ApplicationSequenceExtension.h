#pragma once

namespace app::game
{
	class alignas(16) ApplicationSequenceExtension : public ApplicationExtension, public hh::game::GameManagerListener, public hh::fnd::user::UserInfoEventListener, public hh::fw::FrameworkNotificationListener
	{
	public:
		INSERT_PADDING(80) {};
		GameMode* pGameMode{};
		INSERT_PADDING(192) {};

		ApplicationSequenceExtension()
		{

		}
	};
}