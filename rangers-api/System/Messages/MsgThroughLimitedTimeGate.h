#pragma once

namespace app
{
	class MsgThroughLimitedTimeGate : public hh::fnd::MessageAsyncHandlerInplace<MsgThroughLimitedTimeGate>, public fnd::AppMessage<MsgThroughLimitedTimeGate>
	{
	private:
		inline static uint32_t MessageID = 0x2365;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgThroughLimitedTimeGate() /* : fnd::AppMessage<MsgThroughLimitedTimeGate>(MessageID) */ = delete;
	};
}