#pragma once

namespace app
{
	class MsgCGGTimerNotifyEnabled : public hh::fnd::MessageAsyncHandlerInplace<MsgCGGTimerNotifyEnabled>, public fnd::AppMessage<MsgCGGTimerNotifyEnabled>
	{
	private:
		inline static uint32_t MessageID = 0x20B9;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgCGGTimerNotifyEnabled() /* : fnd::AppMessage<MsgCGGTimerNotifyEnabled>(MessageID) */ = delete;
	};
}