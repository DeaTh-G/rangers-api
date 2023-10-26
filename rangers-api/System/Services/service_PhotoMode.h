#pragma once

namespace app::game
{
	class PhotoModeService : public hh::game::GameService, hh::game::GameStepListener, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "PhotoModeService";

	private:
		INSERT_PADDING(240);

	public:
		csl::math::Vector3 StartPosition{};

	private:
		INSERT_PADDING(112);

	public:
		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
		virtual void* GetClassId();
	};
}