#pragma once

namespace app
{
	class GameDocument;
}

namespace hh::fnd
{
	class Messenger : public RefByHandleObject
	{
	private:
		inline static void* ms_addrSendMessageImmToPlayer = sigScan("\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x30\x4C\x89\xCF\x41\x0F\xB6\xE8", "xxxxxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x146993E00);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpSendMessageImmToPlayer, ms_addrSendMessageImmToPlayer, Messenger*, app::GameDocument*, int, Message&);

	public:
		uint32_t actorId;
		void* pUnk1;
		uint32_t pUnk2;
		uint32_t pUnk3;

		virtual void fUnk1();
		virtual void fUnk2();
		virtual int fUnk3() { return 0; }
		virtual void fUnk4();
		virtual int fUnk5() { return 1; }

		void SendMessageImmToPlayer(app::GameDocument* in_pGameDocument, int in_playerNo, Message& in_rMessage)
		{
			ms_fpSendMessageImmToPlayer(this, in_pGameDocument, in_playerNo, in_rMessage);
		}
	};
}