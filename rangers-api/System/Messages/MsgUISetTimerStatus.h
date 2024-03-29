#pragma once

namespace app::ui
{
	class MsgUISetTimerStatus : public hh::fnd::MessageAsyncHandlerInplace<MsgUISetTimerStatus>, public fnd::AppMessage<MsgUISetTimerStatus>
	{
	private:
		inline static uint32_t MessageID = 0x240F;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgUISetTimerStatus() /* : fnd::AppMessage<MsgUISetTimerStatus>(MessageID) */ = delete;
	};
}