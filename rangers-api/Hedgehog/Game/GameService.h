#pragma once

namespace hh::game
{
	class GameDocument;

	class alignas(8) GameServiceClass
	{
	public:
		const char* pName;
		void* pUnk1{};
		void* pUnk2{};
	};
	
	class alignas(8) GameService : public hh::fnd::Messenger
	{
	public:
		GameDocument* pDocument;
		GameServiceClass* pStaticClass;
		uint32_t unk20;
		csl::fnd::Mutex mutex;

		virtual void* GetClassId();
	};
}