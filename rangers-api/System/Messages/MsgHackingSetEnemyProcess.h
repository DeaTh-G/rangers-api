#pragma once

namespace app
{
	class MsgHackingSetEnemyProcess : public hh::fnd::MessageAsyncHandlerInplace<MsgHackingSetEnemyProcess>, public fnd::AppMessage<MsgHackingSetEnemyProcess>
	{
	private:
		inline static uint32_t MessageID = 0x21D0;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgHackingSetEnemyProcess() /* : fnd::AppMessage<MsgHackingSetEnemyProcess>(MessageID) */ = delete;
	};
}