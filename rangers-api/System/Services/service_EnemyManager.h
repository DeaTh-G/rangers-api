#pragma once

namespace app
{
	class alignas(16) EnemyManager : public hh::game::GameService, hh::game::GameStepListener
	{
	private:
		inline static const char* ms_pServiceName = "EnemyManager";

	public:
		INSERT_PADDING(2);
		int64_t EnemyCount;
		INSERT_PADDING(3170);

		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}