#pragma once

namespace app
{
	class MsgEndMasterTrialParameter : public hh::fnd::MessageAsyncHandlerInplace<MsgEndMasterTrialParameter>, public fnd::AppMessage<MsgEndMasterTrialParameter>
	{
	private:
		inline static uint32_t MessageID = 0x213A;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.

		MsgEndMasterTrialParameter() /* : fnd::AppMessage<MsgEndMasterTrialParameter>(MessageID) */ = delete;
	};
}