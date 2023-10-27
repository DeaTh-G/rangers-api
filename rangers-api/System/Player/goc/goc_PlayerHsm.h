#pragma once

namespace app::player
{
	template <typename T>
	class StatePluginManager;
	class PlayerStateParameter;

	class GOCPlayerHsm : public hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerHsm";

	public:
		INSERT_PADDING(8);
		hh::ut::HsmBase Hsm{};
		INSERT_PADDING(8);
		PlayerStateParameter* pPlayerStateParameter{};
		StatePluginManager<PlayerHsmContext>* pStatePluginManager{};
		INSERT_PADDING(4);
		int StateID{};
		int ParentStateID{};
		INSERT_PADDING(80);

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}

		int GetCurrentStateID()
		{
			return Hsm.getCurrentStateID();
		}
	};
}