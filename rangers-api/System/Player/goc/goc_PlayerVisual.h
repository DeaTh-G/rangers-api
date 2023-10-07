#pragma once

namespace app::player
{
	class GOCPlayerVisual : hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerVisual";

	public:
		INSERT_PADDING(136) {};
		PlayerVisual* pPlayerVisual;
		INSERT_PADDING(112) {};

		template <typename T>
		T* GetVisual()
		{
			if (pPlayerVisual && pPlayerVisual->GetNameHash() == csl::ut::StringMapOperation::hash(T::ms_pName))
				return static_cast<T*>(pPlayerVisual);

			return { nullptr };
		}

		PlayerVisual* GetVisualByHash(size_t in_hash)
		{
			if (pPlayerVisual && pPlayerVisual->GetNameHash() == in_hash)
				return pPlayerVisual;
		
			return { nullptr };
		}

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}
	};
}