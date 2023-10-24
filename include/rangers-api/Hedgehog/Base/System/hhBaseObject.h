#pragma once

namespace hh::fnd
{
	class alignas(8) BaseObject
	{
	protected:
		csl::fnd::IAllocator* pAllocator{};
	public:
		BaseObject(csl::fnd::IAllocator* pAllocator) : pAllocator{ pAllocator } {}
		virtual ~BaseObject() = default;

		csl::fnd::IAllocator* GetAllocator() const
		{
			return pAllocator;
		}

		static void* operator new(size_t count, csl::fnd::IAllocator* pAllocator) {
			return pAllocator->Alloc(count, 8);
		}

		static void operator delete(void* ptr, size_t size) noexcept {
			static_cast<BaseObject*>(ptr)->pAllocator->Free(ptr);
		}

		static void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator) noexcept {
			pAllocator->Free(ptr);
		}
	};
}