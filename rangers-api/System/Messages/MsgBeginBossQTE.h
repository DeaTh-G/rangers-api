#pragma once

namespace app
{
	class MsgBeginBossQTE : public hh::fnd::MessageAsyncHandlerInplace<MsgBeginBossQTE>, public fnd::AppMessage<MsgBeginBossQTE>
	{
	private:
		inline static uint32_t MessageID = 0x2030;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgBeginBossQTE() /* : fnd::AppMessage<MsgBeginBossQTE>(MessageID) */ = delete;
	};
}