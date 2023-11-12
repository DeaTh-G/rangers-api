#pragma once

namespace app::game
{
	class MsgSetDestinationMarkerInvisible : public hh::fnd::MessageAsyncHandlerInplace<MsgSetDestinationMarkerInvisible>, public fnd::AppMessage<MsgSetDestinationMarkerInvisible>
	{
	private:
		inline static uint32_t MessageID = 0x22EE;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgSetDestinationMarkerInvisible() /* : fnd::AppMessage<MsgSetDestinationMarkerInvisible>(MessageID) */ = delete;
	};
}