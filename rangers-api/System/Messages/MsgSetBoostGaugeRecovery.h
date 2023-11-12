#pragma once

namespace app::player
{
	class MsgSetBoostGaugeRecovery : public hh::fnd::MessageAsyncHandlerInplace<MsgSetBoostGaugeRecovery>, public fnd::AppMessage<MsgSetBoostGaugeRecovery>
	{
	private:
		inline static uint32_t MessageID = 0x22E7;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(16);

		MsgSetBoostGaugeRecovery() /* : fnd::AppMessage<MsgSetBoostGaugeRecovery>(MessageID) */ = delete;
	};
}