#pragma once

namespace app::save
{
	class alignas(8) SaveManagerListener
	{
	public:
		virtual ~SaveManagerListener() = default;
		virtual void fUnk1();
		virtual void fUnk2();
		virtual void fUnk3();
	};
}