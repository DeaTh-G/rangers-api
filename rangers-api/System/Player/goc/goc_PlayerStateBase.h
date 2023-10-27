#pragma once

namespace app::player
{
	// Not actually a Game Object Compoment but still retains the GOC prefix for some reason.
	template <typename T>
	class GOCPlayerStateBase : public hh::ut::StateBase<T>
	{

	};
}