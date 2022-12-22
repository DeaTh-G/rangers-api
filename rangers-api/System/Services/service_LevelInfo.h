#pragma once

namespace app::level
{
	class LevelInfo : public hh::game::GameService, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "LevelInfo";
		
	public:
		void* pStageData{};
		INSERT_PADDING(72);
		csl::ut::FixedArray<player::PlayerInformation*, 1> playerInfos{};
		INSERT_PADDING(48);
		
		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};

}
