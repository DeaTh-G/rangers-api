#pragma once

namespace app::ui
{
	class MsgUITimingGaugeReset : public hh::fnd::MessageAsyncHandlerInplace<MsgUITimingGaugeReset>, public fnd::AppMessage<MsgUITimingGaugeReset>
	{
	private:
		inline static uint32_t MessageID = 0x241E;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgUITimingGaugeReset() /* : fnd::AppMessage<MsgUITimingGaugeReset>(MessageID) */ = delete;
	};
}