#pragma once

namespace app::ui
{
	class MsgUISetTimerReset : public hh::fnd::MessageAsyncHandlerInplace<MsgUISetTimerReset>, public fnd::AppMessage<MsgUISetTimerReset>
	{
	private:
		inline static uint32_t MessageID = 0x240E;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgUISetTimerReset() /* : fnd::AppMessage<MsgUISetTimerReset>(MessageID) */ = delete;
	};
}