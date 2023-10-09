#pragma once

namespace hh::fnd
{
	class MessageManager
	{
	public:
		INSERT_PADDING(70) {};
		
		virtual ~MessageManager() = default;

		Messenger* GetMessengerByHandle(uint32_t in_handle)
		{
			auto* pHandleManager = HandleManagerBase::GetSingleton();
			if (pHandleManager)
				return pHandleManager->GetObjectByHandle(in_handle);

			return { nullptr };
		}

		template<typename T>
		T* GetMessengerByHandle(uint32_t in_handle)
		{
			auto* pHandleManager = HandleManagerBase::GetSingleton();
			if (pHandleManager)
				return pHandleManager->GetObjectByHandle<T>(in_handle);

			return { nullptr };
		}
	};
}