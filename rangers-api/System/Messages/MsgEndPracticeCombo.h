#pragma once

namespace app::game
{
	class MsgEndPracticeCombo : public hh::fnd::MessageAsyncHandlerInplace<MsgEndPracticeCombo>, public fnd::AppMessage<MsgEndPracticeCombo>
	{
	private:
		inline static uint32_t MessageID = 0x213F;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgEndPracticeCombo() /* : fnd::AppMessage<MsgEndPracticeCombo>(MessageID) */ = delete;
	};
}