#pragma once

namespace app
{
	class MsgHideKodama : public hh::fnd::MessageAsyncHandlerInplace<MsgHideKodama>, public fnd::AppMessage<MsgHideKodama>
	{
	private:
		inline static uint32_t MessageID = 0x21D4;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgHideKodama() /* : fnd::AppMessage<MsgHideKodama>(MessageID) */ = delete;
	};
}