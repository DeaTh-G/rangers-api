#pragma once

namespace hh::fnd
{
	class MessageManager
	{
	private:
		inline static void* ms_addrStaticMessageManagerUsage = sigScan("\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x89\x43\x20", "xxx????xxxx", (void*)0x1525C0FDF);
		inline static MessageManager** ms_ppMessageManager = reinterpret_cast<MessageManager**>(7 + (size_t)ms_addrStaticMessageManagerUsage + (*(int32_t*)(((char*)ms_addrStaticMessageManagerUsage) + 3)));

	public:
		INSERT_PADDING(70) {};
		
		virtual ~MessageManager() = default;

		inline static MessageManager* GetSingleton()
		{
			return *ms_ppMessageManager;
		}

		inline static Messenger* GetMessengerByHandle(uint32_t in_handle)
		{
			auto* pHandleManager = HandleManagerBase::GetSingleton();

			if (pHandleManager)
				return pHandleManager->GetObjectByHandle(in_handle);

			return { nullptr };
		}

		template<typename T>
		inline static T* GetMessengerByHandle(uint32_t in_handle)
		{
			auto* pHandleManager = HandleManagerBase::GetSingleton();

			if (pHandleManager)
				return pHandleManager->GetObjectByHandle<T>(in_handle);

			return { nullptr };
		}
	};
}