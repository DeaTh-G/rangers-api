#pragma once

namespace app
{
	class MsgSumoPoleIsRopeElectric : public hh::fnd::MessageAsyncHandlerInplace<MsgSumoPoleIsRopeElectric>, public fnd::AppMessage<MsgSumoPoleIsRopeElectric>
	{
	private:
		inline static uint32_t MessageID = 0x2342;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgSumoPoleIsRopeElectric() /* : fnd::AppMessage<MsgSumoPoleIsRopeElectric>(MessageID) */ = delete;
	};
}