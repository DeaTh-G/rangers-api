#pragma once

namespace app::game
{
	class MsgReleaseMap : public hh::fnd::MessageAsyncHandlerInplace<MsgReleaseMap>, public fnd::AppMessage<MsgReleaseMap>
	{
	private:
		inline static uint32_t MessageID = 0x22A8;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(40);

		MsgReleaseMap() /* : fnd::AppMessage<MsgReleaseMap>(MessageID) */ = delete;
	};
}