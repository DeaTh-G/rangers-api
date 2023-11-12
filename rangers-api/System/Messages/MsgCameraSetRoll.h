#pragma once

namespace app::camera
{
	class MsgCameraSetRoll : public hh::fnd::MessageAsyncHandlerInplace<MsgCameraSetRoll>, public fnd::AppMessage<MsgCameraSetRoll>
	{
	private:
		inline static uint32_t MessageID = 0x20A8;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgCameraSetRoll() /* : fnd::AppMessage<MsgCameraSetRoll>(MessageID) */ = delete;
	};
}