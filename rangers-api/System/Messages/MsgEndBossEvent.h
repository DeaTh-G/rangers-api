#pragma once

namespace app
{
	class MsgEndBossEvent : public hh::fnd::MessageAsyncHandlerInplace<MsgEndBossEvent>, public fnd::AppMessage<MsgEndBossEvent>
	{
	private:
		inline static uint32_t MessageID = 0x2125;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgEndBossEvent() /* : fnd::AppMessage<MsgEndBossEvent>(MessageID) */ = delete;
	};
}