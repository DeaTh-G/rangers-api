#pragma once

namespace hh::fnd
{
	template<typename T>
	class Reference {
		T* ptr{ nullptr };
	public:
		Reference() {
		}

		Reference(Reference&& other) {
			this->ptr = other.ptr;
			other.ptr = nullptr;
		}

		Reference(T* rawPtr) {
			rawPtr->Acquire();
			ptr = rawPtr;
		}

		~Reference() {
			if (ptr != nullptr)
				ptr->Free();
		}

		inline Reference<T>& operator=(T* const other) {
			T* old = ptr;

			if (other != nullptr)
				other->Acquire();

			ptr = other;

			if (old != nullptr)
				old->Free();

			return *this;
		}

		inline Reference<T>& operator=(const Reference<T>& other) {
			*this = other.ptr;
			return *this;
		}

		inline Reference<T>& operator=(Reference<T>&& other) {
			this->ptr = other.ptr;
			other.ptr = nullptr;

			return *this;
		}

		inline T& operator*() const {
			return *ptr;
		}

		inline T* operator->() const {
			return ptr;
		}

		inline operator T&() const {
			return *ptr;
		}

		inline operator T*() const {
			return ptr;
		}

		inline bool operator==(const Reference<T>& other) const {
			return ptr == other.ptr;
		}

		inline bool operator==(T* const other) const {
			return ptr == other;
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
