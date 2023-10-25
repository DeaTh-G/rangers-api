#pragma once

namespace csl::ut
{
	class StringMapOperation
	{
		inline static constexpr size_t HASH_MASK = 0x7FFFFFFF;
		inline static constexpr size_t HASH_MAGIC = 31;

	public:
		static size_t hash(const char* in_pKey)
		{
			if (!in_pKey)
				return 0;

			const char* pStr = reinterpret_cast<const char*>(in_pKey);
			size_t hashResult{};
			size_t i = 0;
			char c = *pStr;

			if (*pStr)
			{
				do
				{
					++i;
					hashResult = HASH_MAGIC * hashResult + c;
					c = pStr[i];
				} while (pStr[i]);
			}

			return hashResult & HASH_MASK;
		}
	};
}