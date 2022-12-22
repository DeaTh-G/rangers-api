#pragma once

namespace app::player
{
	class alignas(16) BlackboardBattle : public BlackboardContent
	{
	public:
		INSERT_PADDING(32);
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(12);
		float PhantomRushMeter;
		INSERT_PADDING(80);

		static size_t GetHashedName()
		{
			return csl::ut::StringMapOperation::hash("BlackboardBattle");
		}
	};
}