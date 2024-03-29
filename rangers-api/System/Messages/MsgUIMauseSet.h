#pragma once

namespace app::ui
{
	class MsgUIMauseSet : public hh::fnd::MessageAsyncHandlerInplace<MsgUIMauseSet>, public fnd::AppMessage<MsgUIMauseSet>
	{
	private:
		inline static uint32_t MessageID = 0x23D6;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgUIMauseSet() /* : fnd::AppMessage<MsgUIMauseSet>(MessageID) */ = delete;
	};
}