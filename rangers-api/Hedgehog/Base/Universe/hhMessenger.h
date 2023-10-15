#pragma once

namespace app
{
	class GameManager;
}

namespace hh::fnd
{
	class Messenger : public RefByHandleObject
	{
	protected:
		/*
		 * Sends a message to one particular receiver.
		 */
		bool SendMessage(Handle<Messenger>& receiver, Message& message);

	public:
		void* pMessageManager; // hh::fnd::MessageManager*
		uint32_t messageMask;
		uint32_t pUnk3;

		virtual void* GetClassId();
		virtual bool fUnk2(Message& message) { return !fUnk3(); }
		virtual bool fUnk3() { return false; }
		virtual bool ProcessMessage(Message& message);
		virtual bool IsAcceptingMessages() { return 1; }
	};
}
