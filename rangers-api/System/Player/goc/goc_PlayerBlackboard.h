#pragma once

namespace app::player
{
	class GOCPlayerBlackboard : public hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerBlackboard";

	public:
		Blackboard* pBlackboard{};

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}
	};
}