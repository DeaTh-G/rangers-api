#pragma once

namespace app::camera
{
	class MsgCameraResetLockonParam : public hh::fnd::MessageAsyncHandlerInplace<MsgCameraResetLockonParam>, public fnd::AppMessage<MsgCameraResetLockonParam>
	{
	private:
		inline static uint32_t MessageID = 0x20A4;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgCameraResetLockonParam() /* : fnd::AppMessage<MsgCameraResetLockonParam>(MessageID) */ = delete;
	};
}