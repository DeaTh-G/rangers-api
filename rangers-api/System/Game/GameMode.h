#pragma once

namespace app::game
{
	class GameModeExtension;

	class GameMode : public hh::fnd::Messenger
	{
	public:
		hh::game::GameManager* pGameManager{};
		INSERT_PADDING(88);
		csl::ut::ObjectMoveArray<hh::game::GameService*> Services{};
		csl::ut::ObjectMoveArray<GameModeExtension*> Extensions{};
		INSERT_PADDING(16);
	};
}