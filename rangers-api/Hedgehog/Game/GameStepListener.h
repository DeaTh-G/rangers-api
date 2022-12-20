#pragma once

namespace hh::game
{
	class alignas(8) GameStepListener
	{
	public:
		virtual ~GameStepListener() = default;
		virtual void fUnk1();
		virtual void fUnk2();
		virtual void fUnk3();
	};
}