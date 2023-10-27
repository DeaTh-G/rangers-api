#pragma once

namespace app::player
{
	template<typename T>
	class StatePluginManager : public hh::fnd::BaseObject
	{
	public:
		INSERT_PADDING(16);
		csl::ut::ObjectMoveArray<StatePluginBase*> Plugins;
		INSERT_PADDING(8);

		StatePluginBase* GetStatePlugin(const char* in_pPluginName)
		{
			for (auto* pPlugin : Plugins)
			{
				if (pPlugin == nullptr)
					continue;

				if (pPlugin->GetNameHash() == csl::ut::StringMapOperation::hash(in_pPluginName))
					return pPlugin;
			}

			return { nullptr };
		}

		template <typename T>
		T* GetStatePlugin()
		{
			return (T*)GetStatePlugin(T::GetPluginName());
		}
	};
}