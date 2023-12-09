#pragma once

namespace app::ui
{
	class MsgUIPortalActivate : public hh::fnd::MessageAsyncHandlerInplace<MsgUIPortalActivate>, public fnd::AppMessage<MsgUIPortalActivate>
	{
	private:
		inline static uint32_t MessageID = 0x23F6;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(104);

		MsgUIPortalActivate() /* : fnd::AppMessage<MsgUIPortalActivate>(MessageID) */ = delete;
	};
}