#pragma once

namespace app::player
{
	class alignas(16) BlackboardItem : public BlackboardContent
	{
		inline static const char* ms_pBlackboardName = "BlackboardItem";

	public:
		int32_t RingCapacity{};
		int32_t RingCount{};
		INSERT_PADDING(32);

		size_t GetNameHash() override
		{
			return csl::ut::StringMapOperation::hash(ms_pBlackboardName);
		}

		static const char* GetBlackboardName()
		{
			return ms_pBlackboardName;
		}
	};
}