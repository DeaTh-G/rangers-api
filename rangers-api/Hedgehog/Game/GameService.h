#pragma once

#define GAMESERVICE_CLASS_DECLARATION private:\
		static const hh::game::GameServiceClass* gameServiceClass;\
	public:\
		static const hh::game::GameServiceClass* GetClass();

namespace hh::game
{
	class GameManager;
	class GameService;

	class alignas(8) GameServiceClass
	{
	public:
		const char* pName;
		GameService* (*instantiator)(csl::fnd::IAllocator* pAllocator);
		void* pUnk2{};
	};
	
	class alignas(8) GameService : public hh::fnd::Messenger
	{
	public:
		GameManager* pGameManager;
		GameServiceClass* pStaticClass;
		uint32_t unk20;
		csl::fnd::Mutex mutex;

		virtual void* GetClassId();
	};
}