#pragma once

namespace app::game
{
	class MsgExitEventMenu : public hh::fnd::MessageAsyncHandlerInplace<MsgExitEventMenu>, public fnd::AppMessage<MsgExitEventMenu>
	{
	private:
		inline static uint32_t MessageID = 0x216A;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgExitEventMenu() /* : fnd::AppMessage<MsgExitEventMenu>(MessageID) */ = delete;
	};
}