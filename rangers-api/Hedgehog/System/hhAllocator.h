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
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;

	public:		
		void* Alloc(size_t in_size, size_t in_alignment) override;
		void Free(void* in_pMemory) override;
	};
}