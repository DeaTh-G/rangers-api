#pragma once

namespace hh::game
{
	class GameManagerUnk1 {
		class Unk2 {
			void* unk10;
			void* unk11;
			void* unk12;
		};

		void* unk15;
		Unk2 unk16;
		Unk2 unk17;
		uint32_t unk18;
	};

	class alignas(8) GameStepListener
	{
	public:
		virtual ~GameStepListener() = default;
		virtual void OnGameStep(float timestep);
		virtual void fUnk2() {}
		virtual void fUnk3() {}
	};
	
    class alignas(8) GamePauseListener {
    public:
        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
    };

	class alignas(8) GameUpdateListener
	{
	public:
		virtual ~GameUpdateListener() = default;
		virtual void fUnk1() {}
		virtual void fUnk2() {}
	};

	class GameManager;

	class GameManagerOperationQueue : public fnd::ReferencedObject {
		GameManager* pGameManager;
		csl::ut::MoveArray<void*> unk1;
		csl::ut::MoveArray<void*> unk2;
		GameManagerUnk1 unk3;
		csl::fnd::Mutex mutex;
	public:
		GameManagerOperationQueue(csl::fnd::IAllocator* pAllocator, GameManager* pGameManager);
	};

	class GameManager : public fnd::ReferencedObject, public fnd::ReloaderListener, private csl::ut::NonCopyable
	{
		inline static void* ms_addrStaticGameManagerUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameManager** ms_ppGameManager = reinterpret_cast<GameManager**>(7 + (size_t)ms_addrStaticGameManagerUsage + (*(int32_t*)(((char*)ms_addrStaticGameManagerUsage) + 3)));

		uint32_t unk33;
		uint32_t unk34;
		void* unk35;
		csl::ut::FixedArray<GameObjectLayer*, 32> m_GameObjectLayers{};
		csl::ut::MoveArray<GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<GameService*> m_Services{ pAllocator };
		csl::ut::PointerMap<GameServiceClass*, GameService*> m_ServicesByClass{ pAllocator };
		csl::ut::MoveArray<void*> unk40;
		csl::ut::MoveArray<void*> unk41; // csl::ut::MoveArray<GameManagerListener> m_ManagerListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk42; // csl::ut::MoveArray<GameObjectListener> m_ObjectListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk43; // csl::ut::MoveArray<ComponentListener> m_ComponentListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk44;
		csl::ut::MoveArray<void*> unk45;
		csl::ut::MoveArray<GamePauseListener> m_PauseListeners{ pAllocator };
		csl::ut::MoveArray<GameStepListener> m_StepListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk48;
		csl::ut::MoveArray<void*> unk49;
		void* unk50;
		uint32_t unk51;
		csl::ut::MoveArray<void*> unk52;
		GameManagerUnk1 unk53;
		GameManagerOperationQueue* pOperationQueue;
		uint32_t unk55;
		GameApplication* pApplication;

	public:
		GameManager(csl::fnd::IAllocator* pAllocator, GameApplication* pApplication);

		inline static GameManager* GetSingleton()
		{
			return *ms_ppGameManager;
		}

		template <typename T>
		T* GetService()
		{
			for (auto* pService : m_Services)
			{
				if (pService == nullptr)
					continue;

				if (strcmp(pService->pStaticClass->pName, T::GetServiceName()) == 0)
					return reinterpret_cast<T*>(pService);
			}
		
			return { nullptr };
		}

		GameService* GetService(const char* in_pServiceName)
		{
			for (auto* pService : m_Services)
			{
				if (pService == nullptr)
					continue;

				if (strcmp(pService->pStaticClass->pName, in_pServiceName) == 0)
					return pService;
			}

			return { nullptr };
		}

		// template <typename T>
		// T* GetGameObject()
		// {
		// 	for (auto* pObject : m_Objects)
		// 	{
		// 		if (pObject == nullptr)
		// 			continue;

		// 		if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
		// 			return reinterpret_cast<T*>(pObject);
		// 	}

		// 	return { nullptr };
		// }

		// GameObject* GetGameObject(const char* in_pObjectName)
		// {
		// 	for (auto* pObject : m_Objects)
		// 	{
		// 		if (pObject == nullptr)
		// 			continue;

		// 		if (strcmp(pObject->pObjectName, in_pObjectName) == 0)
		// 			return pObject;
		// 	}

		// 	return { nullptr };
		// }

		void RegisterGameStepListener(GameStepListener& listener);
		void UnregisterGameStepListener(GameStepListener& listener);
		void RegisterGamePauseListener(GamePauseListener& listener);
		void UnregisterGamePauseListener(GamePauseListener& listener);
	};
}

