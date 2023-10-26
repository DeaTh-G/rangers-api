#pragma once

namespace hh::fnd
{
	template<typename T>
	class Reference {
		T* ptr{ nullptr };
	public:
		Reference() {
		}

		~Reference() {
			if (ptr != nullptr)
				ptr->Free();
		}

		inline Reference<T>& operator=(T* const other) {
			T* old = ptr;

			other->Acquire();
			ptr = other;

			if (old != nullptr)
				old->Free();

			return *this;
		}

		inline Reference<T>& operator=(const Reference<T>& other) {
			*this = other->ptr;
		}

		inline T& operator*() {
			return *ptr;
		}

		inline T* operator->() {
			return ptr;
		}

		inline operator T&() {
			return *ptr;
		}
	};

	class alignas(8) ReferencedObject : public BaseObject
	{
		bool isRefCounted{};
		volatile long RefCount{};
		
	public:
		ReferencedObject(csl::fnd::IAllocator* pAllocator, bool isRefCounted) : BaseObject{ pAllocator }, isRefCounted{ isRefCounted } {}

		inline void Acquire() {
			if (isRefCounted) {
				InterlockedExchangeAdd(&RefCount, 1);
			}
		}

		inline void Free() {
			if (isRefCounted) {
				long result = InterlockedExchangeAdd(&RefCount, -1);

				if (result == 1)
					delete this;
			}
		}
	};
}
