#pragma once

namespace csl::ut
{
	template<typename T>
	class MoveArray : public Array<T>
	{
	protected:
		fnd::IAllocator* m_pAllocator{};

		bool isUninitialized()
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

			if (isUninitialized() || !this->m_pBuffer)
			{
				m_pAllocator = new_allocator;
				return;
			}

			if (m_pAllocator == new_allocator)
			{
				return;
			}

			// Make a new m_pBuffer
			T* new_buffer = static_cast<T*>(new_allocator->Alloc(this->capacity() * sizeof(T), 16));

			// Copy buffers
			// memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);
			for (size_t i = 0; i < this->m_length; i++) {
				new (&new_buffer[i]) T(std::move(this->m_pBuffer[i]));
				this->m_pBuffer[i].~T();
			}

			// Free our old m_pBuffer
			if (m_pAllocator && !isUninitialized())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			m_pAllocator = new_allocator;
			this->m_pBuffer = new_buffer;
		}

		void reserve(size_t len)
		{
			// We already have enough reserved, return
			if (len <= this->capacity())
				return;

			// Allocate a new m_pBuffer with the appropriate reserved storage
			T* new_buffer = static_cast<T*>(m_pAllocator->Alloc(sizeof(T) * len, 16));

			if (this->m_pBuffer)
			{
				//memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);
				for (size_t i = 0; i < this->m_length; i++) {
					new (&new_buffer[i]) T(std::move(this->m_pBuffer[i]));
					this->m_pBuffer[i].~T();
				}
			}

			// Free our old m_pBuffer
			if (!isUninitialized())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			// Assign our new m_pBuffer and set the new m_capacity
			this->m_capacity = len;
			this->m_pBuffer = new_buffer;
		}

	public:
		MoveArray()
		{

		}

		MoveArray(const MoveArray<T>& other) : MoveArray<T>{ other.m_capacity, other.m_pAllocator } {
			for (T& x : other) {
				this->push_back(x);
			}
		}

		MoveArray(MoveArray<T>&& other) : MoveArray<T>{ other.m_pAllocator } {
			this->m_pBuffer = other.m_pBuffer;
			this->m_length = other.m_length;
			this->m_capacity = other.m_capacity;
			other.m_pBuffer = nullptr;
			other.m_length = 0;
			other.m_capacity = csl::ut::SIGN_BIT;
		}

		MoveArray(fnd::IAllocator* in_pAllocator) : Array<T>{}, m_pAllocator(in_pAllocator)
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

			if (m_pAllocator && !isUninitialized())
				m_pAllocator->Free(this->m_pBuffer);
		}

		csl::fnd::IAllocator* get_allocator()
		{
			return m_pAllocator;
		}

		void push_back(const T& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(item);
		}

		void push_back(T&& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(std::move(item));
		}

		void push_back_unchecked(const T& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(item);
		}

		void push_back_unchecked(T&& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T(std::move(item));
		}

		void remove(size_t i)
		{
			if (i >= this->m_length)
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
			if (!empty()) {
				for (size_t i = 0; i < this->m_length; i++) {
					this->m_pBuffer[i].~T();
				}
				this->m_length = 0;
			}
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
