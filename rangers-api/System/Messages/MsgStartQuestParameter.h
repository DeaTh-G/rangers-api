#pragma once

namespace app
{
	class MsgStartQuestParameter : public hh::fnd::MessageAsyncHandlerInplace<MsgStartQuestParameter>, public fnd::AppMessage<MsgStartQuestParameter>
	{
	private:
		inline static uint32_t MessageID = 0x2334;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(8);

		MsgStartQuestParameter() /* : fnd::AppMessage<MsgStartQuestParameter>(MessageID) */ = delete;
	};
}