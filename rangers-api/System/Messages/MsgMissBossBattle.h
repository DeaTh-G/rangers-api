#pragma once

namespace app
{
	class MsgMissBossBattle : public hh::fnd::MessageAsyncHandlerInplace<MsgMissBossBattle>, public fnd::AppMessage<MsgMissBossBattle>
	{
	private:
		inline static uint32_t MessageID = 0x221C;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgMissBossBattle() /* : fnd::AppMessage<MsgMissBossBattle>(MessageID) */ = delete;
	};
}