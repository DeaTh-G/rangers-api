#pragma once

namespace app::player
{
	class MsgNotifyEndAuraTrain : public hh::fnd::MessageAsyncHandlerInplace<MsgNotifyEndAuraTrain>, public fnd::AppMessage<MsgNotifyEndAuraTrain>
	{
	private:
		inline static uint32_t MessageID = 0x223A;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgNotifyEndAuraTrain() /* : fnd::AppMessage<MsgNotifyEndAuraTrain>(MessageID) */ = delete;
	};
}