#pragma once

namespace app
{
	class GameManager;
}

namespace hh::fnd
{
	class Messenger : public RefByHandleObject
	{
	private:
		inline static void* ms_addrSendMessageImmToPlayer = sigScan("\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x30\x4C\x89\xCF\x41\x0F\xB6\xE8", "xxxxxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x146993E00);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpSendMessageImmToPlayer, ms_addrSendMessageImmToPlayer, Messenger*, app::GameManager*, int, Message&);

	protected:
		/*
		 * Sends a message to one particular receiver.
		 */
		bool SendMessage(Handle<Messenger>& receiver, Message& message);

	public:
		void* pMessageManager; // hh::fnd::MessageManager*
		uint32_t pUnk2;
		uint32_t pUnk3;

		virtual ~Messenger() {}

		virtual void* GetClassId();
		virtual void fUnk2() { return !fUnk3(); }
		virtual bool fUnk3() { return false; }
		virtual bool ProcessMessage(Message& message);
		virtual bool fUnk5() { return 1; }

		void SendMessageImmToPlayer(app::GameManager* in_pGameManager, int in_playerNo, Message& in_rMessage)
		{
			ms_fpSendMessageImmToPlayer(this, in_pGameManager, in_playerNo, in_rMessage);
		}
	};
}