#pragma once

namespace app
{
	class MyApplication : public hh::game::GameApplication
	{
	public:
		csl::ut::ObjectMoveArray<game::ApplicationExtension*> Extensions{};
	};
}