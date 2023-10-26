#pragma once

namespace app::player
{
	class alignas(16) Sonic : public Player
	{
	private:
		inline static const char* ms_pObjectName = "Sonic";

	public:
		INSERT_PADDING(16);

		static const char* GetObjectName()
		{
			return ms_pObjectName;
		}
	};
}