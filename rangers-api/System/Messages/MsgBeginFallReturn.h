#pragma once

namespace app::player
{
	class MsgBeginFallReturn : public hh::fnd::MessageAsyncHandlerInplace<MsgBeginFallReturn>, public fnd::AppMessage<MsgBeginFallReturn>
	{
	private:
		inline static uint32_t MessageID = 0x203A;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(56);

		MsgBeginFallReturn() /* : fnd::AppMessage<MsgBeginFallReturn>(MessageID) */ = delete;
	};
}