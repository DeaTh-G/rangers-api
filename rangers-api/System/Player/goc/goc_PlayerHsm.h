#pragma once

namespace app::player
{
	class GOCPlayerHsm : public hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerHsm";

	public:
		INSERT_PADDING(8);
		hh::ut::HsmBase Hsm{};
		INSERT_PADDING(8);
		void* pPlayerStateParameter{}; // app::player::PlayerStateParameter
		StatePluginManager<PlayerHsmContext>* pStatePluginManager{};
		INSERT_PADDING(4);
		int32_t StateID{};
		int32_t ParentStateID{};
		INSERT_PADDING(80);

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}

		int32_t GetStateID()
		{
			if (Hsm.CurrentStateIndex)
				return Hsm.pStates[Hsm.CurrentStateIndex - 1]->StateID;

			return -1;
		}
	};
}