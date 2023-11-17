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
		virtual void OnGameStep(float timestep) {}
		virtual void GSL_UnkFunc1() {}
		virtual void GSL_UnkFunc2() {}
	};
	
    class alignas(8) GamePauseListener {
	public:
		virtual ~GamePauseListener() = default;
        virtual void GPL_UnkFunc1() {}
        virtual void GPL_UnkFunc2() {}
    };

	class alignas(8) GameUpdateListener
	{
	public:
		virtual ~GameUpdateListener() = default;
		virtual void GUL_UnkFunc1() {}
		virtual void GUL_UnkFunc2() {}
	};

	class alignas(8) GameManagerListener
	{
	public:
		virtual ~GameManagerListener() = default;
		virtual void GML_UnkFunc1() {}
		virtual void GML_UnkFunc2() {}
		virtual void GML_UnkFunc3() {}
		virtual void GML_UnkFunc4() {}
		virtual void GML_UnkFunc5() {}
		virtual void GML_UnkFunc6() {}
		virtual void GML_UnkFunc7() {}
		virtual void GML_UnkFunc8() {}
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

	class GameApplication;

	class GameManager : public fnd::ReferencedObject, public fnd::ReloaderListener, private csl::ut::NonCopyable
	{
		GameService* CreateService(GameServiceClass* gameServiceClass, csl::fnd::IAllocator* residentAllocator);
	public:
		uint32_t unk33;
		uint32_t unk34;
		void* unk35;
		csl::ut::FixedArray<GameObjectLayer*, 32> m_GameObjectLayers{};
		csl::ut::MoveArray<GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<GameService*> m_Services{ pAllocator };
		csl::ut::PointerMap<GameServiceClass*, GameService*> m_ServicesByClass{ pAllocator };
		csl::ut::MoveArray<void*> unk40;
		csl::ut::MoveArray<GameManagerListener*> m_ManagerListeners{ pAllocator };
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

		GameManager(csl::fnd::IAllocator* pAllocator, GameApplication* pApplication);

		static GameManager* instance;
		static GameManager* GetInstance();

		//template <typename T>
		//T* GetService()
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, T::GetServiceName()) == 0)
		//			return reinterpret_cast<T*>(pService);
		//	}
		//
		//	return { nullptr };
		//}

		//GameService* GetService(const char* in_pServiceName)
		//{
		//	for (auto* pService : m_Services)
		//	{
		//		if (pService == nullptr)
		//			continue;

		//		if (strcmp(pService->pStaticClass->pName, in_pServiceName) == 0)
		//			return pService;
		//	}

		//	return { nullptr };
		//}

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

		GameService* GetService(const GameServiceClass* gameServiceClass);

		template<typename T>
		T* GetService() {
			return static_cast<T*>(GetService(T::GetClass()));
		}

		GameObject* GetGameObject(const char* in_pObjectName)
		{
			for (auto* pObject : m_Objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->pObjectName, in_pObjectName) == 0)
					return pObject;
			}

			return { nullptr };
		}

		template<typename T>
		T* CreateService(csl::fnd::IAllocator* residentAllocator) {
			return static_cast<T*>(CreateService(T::GetClass(), residentAllocator));
		}

		csl::ut::MoveArray<GameService*>& GetServices() {
			return m_Services;
		}

		inline GameApplication* GetApplication() const {
			return pApplication;
		}

		void RegisterService(GameService* service);
		void RegisterObject(GameObject* object, void* transform, GameObject* parent, void* probablyObjInfoOrSomething);
		void RegisterNamedObject(GameObject* object, const char* name, bool copyName, void* transform, GameObject* parent);
		void RegisterGameStepListener(GameStepListener& listener);
		void UnregisterGameStepListener(GameStepListener& listener);
		void RegisterGamePauseListener(GamePauseListener& listener);
		void UnregisterGamePauseListener(GamePauseListener& listener);
	};
}

