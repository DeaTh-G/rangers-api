#pragma once

namespace app::game
{
	class MsgEarnExpPoint : public hh::fnd::MessageAsyncHandlerInplace<MsgEarnExpPoint>, public fnd::AppMessage<MsgEarnExpPoint>
	{
	private:
		inline static uint32_t MessageID = 0x2110;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgEarnExpPoint() /* : fnd::AppMessage<MsgEarnExpPoint>(MessageID) */ = delete;
	};
}