#pragma once

namespace app
{
	class MsgTimeBallStart : public hh::fnd::MessageAsyncHandlerInplace<MsgTimeBallStart>, public fnd::AppMessage<MsgTimeBallStart>
	{
	private:
		inline static uint32_t MessageID = 0x236A;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgTimeBallStart() /* : fnd::AppMessage<MsgTimeBallStart>(MessageID) */ = delete;
	};
}