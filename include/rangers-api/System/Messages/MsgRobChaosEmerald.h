#pragma once

namespace app
{
	class MsgRobChaosEmerald : public hh::fnd::MessageAsyncHandlerInplace<MsgRobChaosEmerald>, public fnd::AppMessage<MsgRobChaosEmerald>
	{
	private:
		inline static uint32_t MessageID = 0x2275;

	public:
		char EmeraldType{};

		MsgRobChaosEmerald() : fnd::AppMessage<MsgRobChaosEmerald>(MessageID)
		{
			
		}

		MsgRobChaosEmerald(char in_emeraldType) : MsgRobChaosEmerald()
		{
			EmeraldType = in_emeraldType;
		}
	};
}