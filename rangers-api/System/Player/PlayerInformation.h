#pragma once

namespace app::player
{
	class PlayerInformation : public hh::fnd::BaseObject
	{
	public:
		INSERT_PADDING(726);
		bool IsGrounded;
		INSERT_PADDING(578);
	};
}