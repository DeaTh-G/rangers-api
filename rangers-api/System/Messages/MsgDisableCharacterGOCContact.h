#pragma once

namespace app
{
	class MsgDisableCharacterGOCContact : public hh::fnd::MessageAsyncHandlerInplace<MsgDisableCharacterGOCContact>, public fnd::AppMessage<MsgDisableCharacterGOCContact>
	{
	private:
		inline static uint32_t MessageID = 0x2106;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgDisableCharacterGOCContact() /* : fnd::AppMessage<MsgDisableCharacterGOCContact>(MessageID) */ = delete;
	};
}