#pragma once

namespace hh::fnd
{
	class BuiltinTypeRegistry : public BaseObject
	{
	public:
		static RflClassNameRegistry* GetClassNameRegistry()
		{
			return csl::fnd::Singleton<RflClassNameRegistry>::GetInstance();
		}

		static RflTypeInfoRegistry* GetTypeInfoRegistry()
		{
			return csl::fnd::Singleton<RflTypeInfoRegistry>::GetInstance();
		}
	};
}