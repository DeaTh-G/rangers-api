#pragma once

namespace app::player
{
	class alignas(16) BlackboardBattle : public BlackboardContent
	{
		inline static const char* ms_pBlackboardName = "BlackboardBattle";

	public:
		INSERT_PADDING(32);
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(12);
		float PhantomRushMeter;
		INSERT_PADDING(80);

		virtual size_t GetNameHash() override
		{
			return csl::ut::StringMapOperation::hash(ms_pBlackboardName);
		}

		static const char* GetBlackboardName()
		{
			return ms_pBlackboardName;
		}
	};
}