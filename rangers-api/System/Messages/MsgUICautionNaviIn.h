#pragma once

namespace app::ui
{
	class MsgUICautionNaviIn : public hh::fnd::MessageAsyncHandlerInplace<MsgUICautionNaviIn>, public fnd::AppMessage<MsgUICautionNaviIn>
	{
	private:
		inline static uint32_t MessageID = 0x239E;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(32);

		MsgUICautionNaviIn() /* : fnd::AppMessage<MsgUICautionNaviIn>(MessageID) */ = delete;
	};
}