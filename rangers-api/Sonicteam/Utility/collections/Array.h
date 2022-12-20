#pragma once

namespace csl::ut
{
	static constexpr size_t SIGN_BIT = ((1u << ((sizeof(size_t) * CHAR_BIT) - 1)));
	
	template<typename T>
	class Array
	{
	protected:
		T* m_pBuffer{};
		size_t m_length{};
		size_t m_capacity{};

		T* get(size_t i) const
		{
			if (!this->m_pBuffer)
				return nullptr;

			return &this->m_pBuffer[i];
		}
		
	public:
		[[nodiscard]] T* begin() const { return get(0); }

		[[nodiscard]] T* end() const { return get(this->m_length); }

		[[nodiscard]] T front() const { return *get(0); }

		[[nodiscard]] size_t size() const
		{
			return this->m_length;
		}

		[[nodiscard]] size_t capacity() const
		{
			return this->m_capacity & ~csl::ut::SIGN_BIT;
		}
	};
}