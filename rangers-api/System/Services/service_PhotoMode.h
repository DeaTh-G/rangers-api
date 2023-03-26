#pragma once

namespace app::game
{
	class PhotoModeService : public hh::game::GameService, hh::game::GameStepListener, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "PhotoModeService";

		INSERT_PADDING(368);

	public:
		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}