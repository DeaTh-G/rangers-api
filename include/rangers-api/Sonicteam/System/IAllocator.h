#pragma once

namespace csl::fnd
{
	class IAllocator
	{
	public:
		virtual ~IAllocator() = default;
		
		virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
		virtual void Free(void* in_pMemory) = 0;
	};
}