#pragma once

namespace hh::fnd
{
	class TlsfHeapAllocatorBase : public csl::fnd::IAllocator
	{
		
	};

	class ThreadSafeTlsfHeapAllocator : public TlsfHeapAllocatorBase
	{
	private:
		inline static FUNCTION_PTR(void, __fastcall, ms_fpDestructor, 0x140132880, ThreadSafeTlsfHeapAllocator*);
		inline static FUNCTION_PTR(void*, __fastcall, ms_fpAlloc, 0x140D43FE0, ThreadSafeTlsfHeapAllocator*, size_t, int);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpFree, 0x140D44000, ThreadSafeTlsfHeapAllocator*, void*);

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
			ms_fpFree(this, in_pMemory);
		}
	};
}