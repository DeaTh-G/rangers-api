#pragma once

namespace app::ui
{
	class MsgUIPortalActivateCountEnd : public hh::fnd::MessageAsyncHandlerInplace<MsgUIPortalActivateCountEnd>, public fnd::AppMessage<MsgUIPortalActivateCountEnd>
	{
	private:
		inline static uint32_t MessageID = 0x23F7;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgUIPortalActivateCountEnd() /* : fnd::AppMessage<MsgUIPortalActivateCountEnd>(MessageID) */ = delete;
	};
}