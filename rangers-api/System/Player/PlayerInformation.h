#pragma once

namespace app::player
{
	class PlayerInformation : public hh::fnd::BaseObject
	{
	public:
		INSERT_PADDING(0x2E6);
		bool IsGrounded;
	};
}