#pragma once

namespace app::camera
{
	class MsgCameraOff : public hh::fnd::MessageAsyncHandlerInplace<MsgCameraOff>, public fnd::AppMessage<MsgCameraOff>
	{
	private:
		inline static uint32_t MessageID = 0x20A1;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(16);

		MsgCameraOff() /* : fnd::AppMessage<MsgCameraOff>(MessageID) */ = delete;
	};
}