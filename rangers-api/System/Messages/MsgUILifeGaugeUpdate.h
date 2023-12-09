#pragma once

namespace app::ui
{
	class MsgUILifeGaugeUpdate : public hh::fnd::MessageAsyncHandlerInplace<MsgUILifeGaugeUpdate>, public fnd::AppMessage<MsgUILifeGaugeUpdate>
	{
	private:
		inline static uint32_t MessageID = 0x23CD;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgUILifeGaugeUpdate() /* : fnd::AppMessage<MsgUILifeGaugeUpdate>(MessageID) */ = delete;
	};
}