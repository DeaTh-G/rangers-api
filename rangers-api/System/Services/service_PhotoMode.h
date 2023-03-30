#pragma once

namespace app::game
{
	class PhotoModeService : public hh::game::GameService, hh::game::GameStepListener, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "PhotoModeService";


	public:
		INSERT_PADDING(240);
		Quaternion m_CameraPosition{};
		INSERT_PADDING(112);

		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}