#pragma once

namespace hh::fnd
{
	class TlsfHeapAllocatorBase : public csl::fnd::IAllocator
	{
	private:
		csl::fnd::IAllocator* pAllocator;
		csl::fnd::TlsfHeapBase* pHeap;
		void* pBuffer;
	};

	class ThreadSafeTlsfHeapAllocator : public TlsfHeapAllocatorBase
	{
	private:
		inline static void* ms_addrDestructor = sigScan("\x48\x89\x5C\x24\x08\x48\x89\x74\x24\x10\x57\x48\x83\xEC\x20\x48\x89\xCE\x89\xD7\x48\x81\xC1\xE8\x00\x00\x00", "xxxxxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x14691D7A0);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpDestructor, ms_addrDestructor, ThreadSafeTlsfHeapAllocator*);
		
		inline static void* ms_addrAlloc = sigScan("\x48\x8B\x49\x10\x48\x8B\x01\x45\x85\xC0", "xxxxxxxxxx", (void*)0x140D43FE0);
		inline static FUNCTION_PTR(void*, __fastcall, ms_fpAlloc, ms_addrAlloc, ThreadSafeTlsfHeapAllocator*, size_t, int);

		csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;

	public:
		~ThreadSafeTlsfHeapAllocator() override
		{
			ms_fpDestructor(this);
		}
		
		void* Alloc(size_t in_size, int in_alignment) override
		{
			return ms_fpAlloc(this, in_size, in_alignment);
		}

		void Free(void* in_pMemory) override
		{
			
		}
	};
}