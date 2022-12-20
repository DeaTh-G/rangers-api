#pragma once

namespace hh::fnd
{
	class Message
	{
	public:
		uint32_t ID{};
		uint32_t Sender{};
		uint32_t Receiver{};
		char Handled{};
		bool Broadcasted{};
		const uint32_t Mask{ (uint32_t)-1 };

		Message(uint32_t in_id)
		{
			ID = in_id;
		}

		virtual Message* Clone()
		{
			return new Message(ID);
		}

		virtual ~Message() = default;
	};

	class MessageAsyncHandler : ReferencedObject
	{
	public:
		void* pUnk1{};
		char Unk2{};

		virtual ~MessageAsyncHandler() = default;
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		
	};
}

namespace app::fnd
{
	template <typename T>
	class AppMessage : public hh::fnd::Message
	{
	public:
		AppMessage(uint32_t in_id) : Message(in_id)
		{
			
		}
		
		AppMessage<T>* Clone() override
		{
			return new AppMessage<T>(ID);
		}
	};
}