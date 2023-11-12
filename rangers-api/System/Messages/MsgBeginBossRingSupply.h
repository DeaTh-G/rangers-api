#pragma once

namespace app
{
	class MsgBeginBossRingSupply : public hh::fnd::MessageAsyncHandlerInplace<MsgBeginBossRingSupply>, public fnd::AppMessage<MsgBeginBossRingSupply>
	{
	private:
		inline static uint32_t MessageID = 0x2031;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgBeginBossRingSupply() /* : fnd::AppMessage<MsgBeginBossRingSupply>(MessageID) */ = delete;
	};
}