#pragma once

namespace app::game
{
	class MsgEndPauseGame : public hh::fnd::MessageAsyncHandlerInplace<MsgEndPauseGame>, public fnd::AppMessage<MsgEndPauseGame>
	{
	private:
		inline static uint32_t MessageID = 0x213E;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgEndPauseGame() /* : fnd::AppMessage<MsgEndPauseGame>(MessageID) */ = delete;
	};
}