#pragma once

namespace app
{
	class MsgGetIfSpawnBombEnabled : public hh::fnd::MessageAsyncHandlerInplace<MsgGetIfSpawnBombEnabled>, public fnd::AppMessage<MsgGetIfSpawnBombEnabled>
	{
	private:
		inline static uint32_t MessageID = 0x2192;

	public:
		// This class, and its size was auto-generated by ĐeäTh and is lacking documentation.
		// Before using ensure that the size matches the size from the game and create a matching constructor.
		// After those steps the delete call on the constructor can be deleted and the base class constructor can be called normally.
		INSERT_PADDING(56);

		MsgGetIfSpawnBombEnabled() /* : fnd::AppMessage<MsgGetIfSpawnBombEnabled>(MessageID) */ = delete;
	};
}