#pragma once

namespace app::level
{
	class ChallengeTimeManager : public hh::game::GameService
	{
	private:
		inline static const char* ms_pServiceName = "ChallengeTimeManager";

	public:
		INSERT_PADDING(16);
		int32_t ChallengePhase;
		INSERT_PADDING(52);

		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}