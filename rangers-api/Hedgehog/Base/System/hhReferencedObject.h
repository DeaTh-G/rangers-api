#pragma once

namespace hh::fnd
{
	class alignas(8) ReferencedObject : public BaseObject
	{
	public:
		ThreadSafeTlsfHeapAllocator* pAllocator{};
		int Unk1{};
		int RefCount{};
		
		inline static void* operator new(size_t in_size, void* in_pMemory) { return in_pMemory; }
	};

	class RefByHandleObject : public ReferencedObject
	{
	public:
		uint32_t Handle{};
	};
}