#pragma once

namespace app::level
{
	class LevelInfo : public hh::game::GameService, public app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "LevelInfo";
		
	public:
		app::level::StageData* pStageData{};
		INSERT_PADDING(72);
		csl::ut::FixedArray<PlayerInformation*, 1> PlayerInfos{};
		INSERT_PADDING(48);
		
		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}

		PlayerInformation* GetPlayerInformation(size_t in_playerNo = 0) const
		{
			return PlayerInfos[in_playerNo];
		}
	};
}