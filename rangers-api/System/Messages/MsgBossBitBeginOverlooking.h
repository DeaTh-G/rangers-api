#pragma once

namespace app
{
	class MsgBossBitBeginOverlooking : public hh::fnd::MessageAsyncHandlerInplace<MsgBossBitBeginOverlooking>, public fnd::AppMessage<MsgBossBitBeginOverlooking>
	{
	private:
		inline static uint32_t MessageID = 0x205E;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgBossBitBeginOverlooking() /* : fnd::AppMessage<MsgBossBitBeginOverlooking>(MessageID) */ = delete;
	};
}