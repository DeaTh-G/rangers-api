#pragma once

namespace app
{
	class MsgBeginWaterFall : public hh::fnd::MessageAsyncHandlerInplace<MsgBeginWaterFall>, public fnd::AppMessage<MsgBeginWaterFall>
	{
	private:
		inline static uint32_t MessageID = 0x2052;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgBeginWaterFall() /* : fnd::AppMessage<MsgBeginWaterFall>(MessageID) */ = delete;
	};
}