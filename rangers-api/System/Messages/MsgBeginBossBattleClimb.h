#pragma once

namespace app
{
	class MsgBeginBossBattleClimb : public hh::fnd::MessageAsyncHandlerInplace<MsgBeginBossBattleClimb>, public fnd::AppMessage<MsgBeginBossBattleClimb>
	{
	private:
		inline static uint32_t MessageID = 0x202B;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgBeginBossBattleClimb() /* : fnd::AppMessage<MsgBeginBossBattleClimb>(MessageID) */ = delete;
	};
}