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
		inline static FUNCTION_PTR(void, __fastcall, ms_fpSendMessageImmToPlayer, 0x1401330A0, Messenger*, app::GameDocument*, int, Message&);

	public:
		void* pUnk1;
		void* pUnk2;
		void* pUnk3;

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