#pragma once

namespace app
{
	class MsgSumoPoleSlingShotStart : public hh::fnd::MessageAsyncHandlerInplace<MsgSumoPoleSlingShotStart>, public fnd::AppMessage<MsgSumoPoleSlingShotStart>
	{
	private:
		inline static uint32_t MessageID = 0x234C;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(16);

		MsgSumoPoleSlingShotStart() /* : fnd::AppMessage<MsgSumoPoleSlingShotStart>(MessageID) */ = delete;
	};
}