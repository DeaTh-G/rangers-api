#pragma once

namespace app
{
	class MsgAllowPuzzleBlockActionOnCyloop : public hh::fnd::MessageAsyncHandlerInplace<MsgAllowPuzzleBlockActionOnCyloop>, public fnd::AppMessage<MsgAllowPuzzleBlockActionOnCyloop>
	{
	private:
		inline static uint32_t MessageID = 0x200F;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgAllowPuzzleBlockActionOnCyloop() /* : fnd::AppMessage<MsgAllowPuzzleBlockActionOnCyloop>(MessageID) */ = delete;
	};
}