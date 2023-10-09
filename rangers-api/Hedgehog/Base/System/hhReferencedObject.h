#pragma once

namespace hh::fnd
{
	class alignas(8) ReferencedObject : public BaseObject
	{
	public:
		ThreadSafeTlsfHeapAllocator* pAllocator{};
		int Unk1{};
		int RefCount{};
		
		inline static void* operator new(size_t size, void* memory) { return memory; }
	};

	class RefByHandleObject : public ReferencedObject
	{
		int Handle{};
	};
}