#pragma once

namespace app::level
{
	class PlayerInformation : public hh::fnd::BaseObject
	{
	public:
		INSERT_PADDING(8);
		int PlayerHandle{};
		INSERT_PADDING(4);
		uint8_t CharacterIndex{};
		INSERT_PADDING(726);
		bool IsGrounded{};
		INSERT_PADDING(592);
	};
}