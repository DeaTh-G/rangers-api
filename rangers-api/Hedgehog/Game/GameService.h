#pragma once

namespace app
{
	class GameDocument;
}

namespace hh::game
{
	class alignas(8) GameServiceClass
	{
	public:
		const char* pName;
		void* pUnk1{};
		void* pUnk2{};
	};
	
	class GameService : public hh::fnd::Messenger
	{
	public:
		app::GameDocument* pDocument;
		GameServiceClass* pStaticClass;

		virtual void fUnk1() = 0;
		virtual void fUnk2() = 0;

	private:
		INSERT_PADDING(48);
	};
}