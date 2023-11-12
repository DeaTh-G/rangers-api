#pragma once

namespace app::player
{
	class MsgBoostCancel : public hh::fnd::MessageAsyncHandlerInplace<MsgBoostCancel>, public fnd::AppMessage<MsgBoostCancel>
	{
	private:
		inline static uint32_t MessageID = 0x2058;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgBoostCancel() /* : fnd::AppMessage<MsgBoostCancel>(MessageID) */ = delete;
	};
}