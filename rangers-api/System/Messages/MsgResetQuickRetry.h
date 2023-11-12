#pragma once

namespace app::player
{
	class MsgResetQuickRetry : public hh::fnd::MessageAsyncHandlerInplace<MsgResetQuickRetry>, public fnd::AppMessage<MsgResetQuickRetry>
	{
	private:
		inline static uint32_t MessageID = 0x22C8;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgResetQuickRetry() /* : fnd::AppMessage<MsgResetQuickRetry>(MessageID) */ = delete;
	};
}