#pragma once

namespace csl::ut
{
	static constexpr size_t SIGN_BIT = ((1u << ((sizeof(size_t) * CHAR_BIT) - 1)));

	template<typename T>
	class MoveArray
	{
	protected:
		T* pBuffer{};
		uint32_t Length{};
		uint32_t Capacity{};
		fnd::IAllocator* pAllocator{};

		T* get(size_t in_index) const
		{
			if (!this->pBuffer)
				return nullptr;

			return &this->pBuffer[in_index];
		}

		bool isInplace()
		{
			return this->Capacity & csl::ut::SIGN_BIT;
		}

	public:
		void change_allocator(fnd::IAllocator* in_pAllocator)
		{
			if (!in_pAllocator)
			{
				return;
			}

			if (isInplace() || !this->pBuffer)
			{
				pAllocator = in_pAllocator;
				return;
			}

			if (pAllocator == in_pAllocator)
			{
				return;
			}

			// Make a new m_pBuffer
			void* new_buffer = in_pAllocator->Alloc(this->capacity() * sizeof(T), 16);

			// Copy buffers
			memcpy(new_buffer, this->pBuffer, sizeof(T) * this->length);

			// Free our old m_pBuffer
			if (pAllocator && !isInplace())
			{
				pAllocator->Free(this->pBuffer);
			}

			pAllocator = in_pAllocator;
			this->pBuffer = static_cast<T*>(new_buffer);
		}

		void reserve(uint32_t in_length)
		{
			// We already have enough reserved, return
			if (in_length <= this->capacity())
				return;

			// Allocate a new m_pBuffer with the appropriate reserved storage
			void* new_buffer = pAllocator->Alloc(sizeof(T) * in_length, 16);

			if (this->pBuffer)
			{
				memcpy(new_buffer, this->pBuffer, sizeof(T) * this->Length);
			}

			// Free our old m_pBuffer
			if (!isInplace())
			{
				pAllocator->Free(this->pBuffer);
			}

			// Assign our new m_pBuffer and set the new m_capacity
			this->Capacity = in_length;
			this->pBuffer = static_cast<T*>(new_buffer);
		}

		MoveArray()
		{

		}

		MoveArray(fnd::IAllocator* in_pAllocator) : pAllocator(in_pAllocator)
		{

		}

		MoveArray(uint32_t in_capacity, fnd::IAllocator* in_pAllocator) : MoveArray(in_pAllocator)
		{
			reserve(in_capacity);
		}

		~MoveArray()
		{
			if (pAllocator && !isInplace())
				pAllocator->Free(this->pBuffer);
		}

		[[nodiscard]] T* begin() const { return get(0); }

		[[nodiscard]] T* end() const { return get(this->Length); }

		[[nodiscard]] T front() const { return *get(0); }

		[[nodiscard]] uint32_t size() const
		{
			return this->Length;
		}

		[[nodiscard]] uint32_t capacity() const
		{
			return this->Capacity & ~csl::ut::SIGN_BIT;
		}

		csl::fnd::IAllocator* get_allocator()
		{
			return pAllocator;
		}

		void push_back(const T& item)
		{
			this->Length++;
			if (this->Length > this->capacity())
			{
				reserve(this->Length * 2);
			}

			this->pBuffer[this->Length - 1] = item;
		}

		void push_back_unchecked(const T& item)
		{
			this->Length++;
			this->pBuffer[this->Length - 1] = item;
		}

		void remove(size_t in_index)
		{
			if (in_index > this->Length)
				return;

			this->pBuffer[in_index] = this->pBuffer[in_index + 1];
			this->Length--;
		}

		bool empty()
		{
			return this->Length == 0;
		}

		void clear()
		{
			if (!empty())
				this->Length = 0;
		}

		void swap(MoveArray& in_rArray)
		{
			auto* tempBuffer = this->pBuffer;
			auto tempLen = this->Length;
			auto tempCap = this->Capacity;
			auto* tempAllocator = this->pAllocator;

			this->pBuffer = in_rArray.m_pBuffer;
			this->Length = in_rArray.m_length;
			this->Capacity = in_rArray.m_capacity;
			this->pAllocator = in_rArray.m_pAllocator;

			in_rArray.pBuffer = tempBuffer;
			in_rArray.Length = tempLen;
			in_rArray.Capacity = tempCap;
			in_rArray.pAllocator = tempAllocator;
		}

		uint32_t find(const T& in_rItem) const
		{
			for (uint32_t i = 0; i < this->Length; i++)
			{
				if (*this->get(i) == in_rItem)
					return i;
			}

			return -1;
		}

		const T& operator[] (uint32_t in_index) const
		{
			return *this->get(in_index);
		}

		T& operator[] (uint32_t in_index)
		{
			return *this->get(in_index);
		}
	};
}