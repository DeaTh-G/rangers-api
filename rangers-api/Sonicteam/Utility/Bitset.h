#pragma once

#ifndef EXPORTING_TYPES
#include <type_traits>
#endif

namespace csl::ut
{
	template <typename T>
	class Bitset
	{
		T m_dummy;
		
	public:
		Bitset()
		{
			reset();
		}

		Bitset(T value) : m_dummy(value){}

#ifndef EXPORTING_TYPES
		// This doesn't actually exist, i just want to make bits easily
		template<typename... TArgs>
		constexpr Bitset(TArgs... bits)
		{
			reset();
			(set(bits), ...);
		}
		
		constexpr void reset()
		{
			m_dummy = T();
		}

		constexpr void reset(T bit)
		{
			m_dummy = T{ static_cast<std::underlying_type_t<T>>(m_dummy) & ~(1 << static_cast<std::underlying_type_t<T>>(bit)) };
		}

		constexpr void flip(T bit)
		{
			m_dummy = T{ static_cast<std::underlying_type_t<T>>(m_dummy) & (1 << static_cast<std::underlying_type_t<T>>(bit)) };
		}
		
		constexpr void set(T bit)
		{
			m_dummy = T{ static_cast<std::underlying_type_t<T>>(m_dummy) & (1 << static_cast<std::underlying_type_t<T>>(bit)) };
		}

		void set(T bit, bool flag)
		{
			if (flag)
				set(bit);
			else
				reset(bit);
		}

		constexpr T value() const
		{
			return m_dummy;
		}
		
		constexpr bool test(T bit) const
		{
			return static_cast<std::underlying_type_t<T>>(m_dummy) & (1 << static_cast<std::underlying_type_t<T>>(bit));
		}
		
		operator T() const { return m_dummy; }
#endif
	};
}
