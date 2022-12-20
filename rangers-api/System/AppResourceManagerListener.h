#pragma once

namespace app::fnd
{
	class alignas(8) AppResourceManagerListener
	{
	public:
		virtual ~AppResourceManagerListener() = default;
		virtual void fUnk1();
	};
}