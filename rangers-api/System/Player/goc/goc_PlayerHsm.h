#pragma once

namespace app::player
{
	class GOCPlayerHsm : hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerHsm";

		INSERT_PADDING(8);
		void* m_pUnkVftable;

	public:
		INSERT_PADDING(56);
		void* pState;                // app::player::PlayerStateActionBase
		INSERT_PADDING(48);
		void* pPlayerStateParameter; // app::player::PlayerStateParameter
		StatePluginManager<PlayerHsmContext>* pStatePluginManager;
		INSERT_PADDING(4);
		int32_t StateID;
		int32_t ParentStateID;
		INSERT_PADDING(80);

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}

		// TODO (Hyper): identify what the vftable is, this is just what the game does with it.
		int32_t GetStateID()
		{
			int32_t offset = *(int32_t*)((int64_t)&m_pUnkVftable + 0x0C);

			if (offset)
				return *(int32_t*)(*(int64_t*)(*(int64_t*)((int64_t)&m_pUnkVftable + 0x20) + 8 * offset - 8) + 0x18);

			return -1;
		}
	};
}