#pragma once

namespace app
{
	class MsgGimmickGetEventInfo : public hh::fnd::MessageAsyncHandlerInplace<MsgGimmickGetEventInfo>, public fnd::AppMessage<MsgGimmickGetEventInfo>
	{
	private:
		inline static uint32_t MessageID = 0x21B3;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(88);

		MsgGimmickGetEventInfo() /* : fnd::AppMessage<MsgGimmickGetEventInfo>(MessageID) */ = delete;
	};
}