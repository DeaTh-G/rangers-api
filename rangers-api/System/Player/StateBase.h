#pragma once

namespace app::player
{
	class PlayerState : public GOCPlayerStateBase<PlayerHsmContext>
	{

	};

	class PlayerStateBase : public PlayerState
	{

	};

	class PlayerStateActionBase : public PlayerStateBase
	{

	};
}