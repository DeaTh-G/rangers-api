#pragma once

namespace csl::ut
{
	template<typename T>
	class MoveArray : public Array<T>
	{
	protected:
		fnd::IAllocator* m_pAllocator{};

		bool isInplace()
		{
			return this->m_capacity & csl::ut::SIGN_BIT;
		}

	public:
		void change_allocator(fnd::IAllocator* new_allocator)
		{
			if (!new_allocator)
			{
				return;
			}

			if (isInplace() || !this->m_pBuffer)
			{
				m_pAllocator = new_allocator;
				return;
			}

			if (m_pAllocator == new_allocator)
			{
				return;
			}

			// Make a new m_pBuffer
			void* new_buffer = new_allocator->Alloc(this->capacity() * sizeof(T), 16);

			// Copy buffers
			memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);

			// Free our old m_pBuffer
			if (m_pAllocator && !isInplace())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			m_pAllocator = new_allocator;
			this->m_pBuffer = static_cast<T*>(new_buffer);
		}

		void reserve(size_t len)
		{
			// We already have enough reserved, return
			if (len <= this->capacity())
				return;

			// Allocate a new m_pBuffer with the appropriate reserved storage
			void* new_buffer = m_pAllocator->Alloc(sizeof(T) * len, 16);

			if (this->m_pBuffer)
			{
				memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);
			}

			// Free our old m_pBuffer
			if (!isInplace())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			// Assign our new m_pBuffer and set the new m_capacity
			this->m_capacity = len;
			this->m_pBuffer = static_cast<T*>(new_buffer);
		}

	public:
		MoveArray()
		{

		}

		MoveArray(fnd::IAllocator* in_pAllocator) : m_pAllocator(in_pAllocator)
		{

		}

		MoveArray(size_t in_capacity, fnd::IAllocator* in_pAllocator) : MoveArray(in_pAllocator)
		{
			reserve(in_capacity);
		}

		~MoveArray()
		{
			for (size_t i = 0; i < this->m_length; i++) {
				this->m_pBuffer[i].~T();
			}

			if (m_pAllocator && !isInplace())
				m_pAllocator->Free(this->m_pBuffer);
		}

		csl::fnd::IAllocator* get_allocator()
		{
			return m_pAllocator;
		}

		void push_back(const T& item)
		{
			this->m_length++;
			if (this->m_length > this->capacity())
			{
				reserve(this->m_length * 2);
			}

			this->m_pBuffer[this->m_length - 1] = item;
		}

		void push_back(T&& item)
		{
			this->m_length++;
			if (this->m_length > this->capacity())
			{
				reserve(this->m_length * 2);
			}

			this->m_pBuffer[this->m_length - 1] = std::move(item);
		}

		void push_back_unchecked(const T& item)
		{
			this->m_length++;
			this->m_pBuffer[this->m_length - 1] = item;
		}

		void push_back_unchecked(T&& item)
		{
			this->m_length++;
			this->m_pBuffer[this->m_length - 1] = std::move(item);
		}

		void remove(size_t i)
		{
			if (i > this->m_length)
				return;

			this->m_pBuffer[i].~T();

			for (size_t j = i + 1; j < this->m_length; j++)
				this->m_pBuffer[j - 1] = std::move(this->m_pBuffer[j]);

			this->m_length--;
		}

		bool empty()
		{
			return this->m_length == 0;
		}

		void clear()
		{
			if (!empty())
				this->m_length = 0;
		}

		void swap(MoveArray& rArray)
		{
			auto* tempBuffer = this->m_pBuffer;
			auto tempLen = this->m_length;
			auto tempCap = this->m_capacity;
			auto* tempAllocator = this->m_pAllocator;

			this->m_pBuffer = rArray.m_pBuffer;
			this->m_length = rArray.m_length;
			this->m_capacity = rArray.m_capacity;
			this->m_pAllocator = rArray.m_pAllocator;

			rArray.m_pBuffer = tempBuffer;
			rArray.m_length = tempLen;
			rArray.m_capacity = tempCap;
			rArray.m_pAllocator = tempAllocator;
		}

		template<typename U>
		size_t find(const U& item) const
		{
			for (size_t i = 0; i < this->m_length; i++)
			{
				if (*this->get(i) == item)
					return i;
			}

			return -1;
		}

		const T& operator[] (size_t i) const
		{
			return *this->get(i);
		}

		T& operator[] (size_t i)
		{
			return *this->get(i);
		}
	};
}
