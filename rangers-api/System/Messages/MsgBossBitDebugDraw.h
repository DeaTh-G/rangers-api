#pragma once

namespace app
{
	class MsgBossBitDebugDraw : public hh::fnd::MessageAsyncHandlerInplace<MsgBossBitDebugDraw>, public fnd::AppMessage<MsgBossBitDebugDraw>
	{
	private:
		inline static uint32_t MessageID = 0x2061;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(56);

		MsgBossBitDebugDraw() /* : fnd::AppMessage<MsgBossBitDebugDraw>(MessageID) */ = delete;
	};
}