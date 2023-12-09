#pragma once

namespace app
{
	class MsgBossRifleBeastEraseRing : public hh::fnd::MessageAsyncHandlerInplace<MsgBossRifleBeastEraseRing>, public fnd::AppMessage<MsgBossRifleBeastEraseRing>
	{
	private:
		inline static uint32_t MessageID = 0x208F;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgBossRifleBeastEraseRing() /* : fnd::AppMessage<MsgBossRifleBeastEraseRing>(MessageID) */ = delete;
	};
}