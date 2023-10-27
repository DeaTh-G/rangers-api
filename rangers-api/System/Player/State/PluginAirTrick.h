#pragma once

namespace app::player
{
	class StatePluginAirTrick : PlayerStatePlugin
	{
	private:
		inline static const char* ms_pName = "VisualSuperSonic";

	public:
		INSERT_PADDING(24);

		inline static const char* GetPluginName()
		{
			return ms_pName;
		}
	};
}