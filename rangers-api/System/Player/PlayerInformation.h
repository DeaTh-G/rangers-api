#pragma once

namespace app::level
{
	class PlayerInformation : public hh::fnd::BaseObject
	{
	public:
		INSERT_PADDING(8);
		int PlayerHandle{};
		INSERT_PADDING(730) {};
		bool IsGrounded{};
		INSERT_PADDING(592) {};
	};
}