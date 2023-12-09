#pragma once

namespace app::ui
{
	class MsgUINotifyUpdatePosition : public hh::fnd::MessageAsyncHandlerInplace<MsgUINotifyUpdatePosition>, public fnd::AppMessage<MsgUINotifyUpdatePosition>
	{
	private:
		inline static uint32_t MessageID = 0x23E7;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgUINotifyUpdatePosition() /* : fnd::AppMessage<MsgUINotifyUpdatePosition>(MessageID) */ = delete;
	};
}