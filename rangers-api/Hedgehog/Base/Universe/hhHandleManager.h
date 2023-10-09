#pragma once

namespace hh::fnd
{
	class Messenger;

	class HandleTableEntry
	{
	public:
		uint32_t Handle{};
		Messenger* pMessenger{};
	};

	class HandleManagerBase
	{
	private:
		inline static void* ms_addrStaticHandleManagerUsage = sigScan("\x48\x89\x05\xCC\xCC\xCC\xCC\x48\x89\xF8", "xxx????xxx", (void*)0x152BA6262);
		inline static HandleManagerBase** ms_ppHandleManager = reinterpret_cast<HandleManagerBase**>(7 + (size_t)ms_addrStaticHandleManagerUsage + (*(int32_t*)(((char*)ms_addrStaticHandleManagerUsage) + 3)));

	public:
		csl::fnd::IAllocator* pAllocator{};
		INSERT_PADDING(8) {};
		csl::ut::ObjectMoveArray<HandleTableEntry> Handles{};
		INSERT_PADDING(56) {};

		inline static HandleManagerBase* GetSingleton()
		{
			return *ms_ppHandleManager;
		}

		Messenger* GetObjectByHandle(uint32_t in_handle);
		template<typename T>
		T* GetObjectByHandle(uint32_t in_handle);

		virtual ~HandleManagerBase() = default;
	};
}