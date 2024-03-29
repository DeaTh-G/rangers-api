#pragma once

namespace app
{
	class MsgGiantDrainPlugUnplugged : public hh::fnd::MessageAsyncHandlerInplace<MsgGiantDrainPlugUnplugged>, public fnd::AppMessage<MsgGiantDrainPlugUnplugged>
	{
	private:
		inline static uint32_t MessageID = 0x21AD;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgGiantDrainPlugUnplugged() /* : fnd::AppMessage<MsgGiantDrainPlugUnplugged>(MessageID) */ = delete;
	};
}