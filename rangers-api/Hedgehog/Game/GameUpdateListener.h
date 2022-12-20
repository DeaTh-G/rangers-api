#pragma once

namespace hh::game
{
	class alignas(8) GameUpdateListener
	{
	public:
		virtual ~GameUpdateListener() = default;
		virtual void fUnk1();
		virtual void fUnk2();
	};
}