#pragma once

namespace app::player
{
	class StatePluginBase : public hh::fnd::ReferencedObject
	{
	private:
		INSERT_PADDING(16);

	public:
		virtual uint32_t GetNameHash() = 0;
		virtual void fUnk1() = 0;
		virtual void fUnk2() = 0;
		virtual void fUnk3() = 0;
		virtual void fUnk4() = 0;
		virtual void fUnk5() = 0;
	};

	template<typename T>
	class StatePlugin : public StatePluginBase
	{

	};
}