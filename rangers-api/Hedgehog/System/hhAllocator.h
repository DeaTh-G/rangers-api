#pragma once

namespace hh::fnd
{
	class TlsfHeapAllocatorBase : public csl::fnd::IAllocator
	{
	private:
		csl::fnd::IAllocator* pAllocator;
		csl::fnd::TlsfHeapBase* pHeap;
		void* pBuffer;

	public:
		TlsfHeapAllocatorBase(csl::fnd::TlsfHeapBase* heap);
	};

	class ThreadSafeTlsfHeapAllocator : public TlsfHeapAllocatorBase
	{
	public:
		struct SetupInfo {
			size_t memorySize;
			bool unk;
		};
	private:
	public:
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;

		ThreadSafeTlsfHeapAllocator(const char* name);
		void Setup(csl::fnd::IAllocator* memoryRouterAllocator, const SetupInfo& setupInfo);
		void* Alloc(size_t in_size, size_t in_alignment) override;
		void Free(void* in_pMemory) override;
	};
}