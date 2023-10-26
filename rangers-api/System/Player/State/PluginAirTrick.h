#pragma once

namespace app::player
{
	class StatePluginAirTrick : PlayerStatePlugin
	{
	public:
		INSERT_PADDING(24);

		inline static const char* GetPluginName()
		{
			return "StatePluginAirTrick";
		}
	};
}