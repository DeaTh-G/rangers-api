#pragma once

namespace app
{
	class MsgTimeBombLevitationStart : public hh::fnd::MessageAsyncHandlerInplace<MsgTimeBombLevitationStart>, public fnd::AppMessage<MsgTimeBombLevitationStart>
	{
	private:
		inline static uint32_t MessageID = 0x236D;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgTimeBombLevitationStart() /* : fnd::AppMessage<MsgTimeBombLevitationStart>(MessageID) */ = delete;
	};
}