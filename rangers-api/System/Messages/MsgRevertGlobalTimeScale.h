#pragma once

namespace app::game
{
	class MsgRevertGlobalTimeScale : public hh::fnd::MessageAsyncHandlerInplace<MsgRevertGlobalTimeScale>, public fnd::AppMessage<MsgRevertGlobalTimeScale>
	{
	private:
		inline static uint32_t MessageID = 0x22D3;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(24);

		MsgRevertGlobalTimeScale() /* : fnd::AppMessage<MsgRevertGlobalTimeScale>(MessageID) */ = delete;
	};
}