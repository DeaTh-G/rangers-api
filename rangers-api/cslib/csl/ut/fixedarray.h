#pragma once

namespace csl::ut
{
	template<typename T, size_t Len>
	class FixedArray
	{
		T Items[Len];

	public:
		constexpr size_t size() const
		{
			return Len;
		}

		constexpr const T* begin() const
		{
			return Items;
		}

		constexpr const T* end() const
		{
			return &Items[Len];
		}

		constexpr T* begin()
		{
			return Items;
		}

		constexpr T* end()
		{
			return &Items[Len];
		}
		
		constexpr T operator[] (size_t in_index) const
		{
			return Items[in_index];
		}

		constexpr T& operator[] (size_t in_index)
		{
			return Items[in_index];
		}
	};
}