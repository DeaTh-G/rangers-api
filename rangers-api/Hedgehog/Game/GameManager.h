#pragma once

namespace hh::game
{
	class GameManagerListener
	{
	public:
		virtual ~GameManagerListener() = default;

		// TODO: 8 More Virtual Functions
	};

	class GameObjectLayer;
	class GameObjectListener;
	class ComponentListener;

	class GameManager : public hh::fnd::ReferencedObject, public hh::fnd::ReloaderListener, csl::ut::NonCopyable
	{
	private:
		inline static void* ms_addrStaticGameDocumentUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameManager** ms_ppGameDocument = reinterpret_cast<GameManager**>(7 + (size_t)ms_addrStaticGameDocumentUsage + (*(int32_t*)(((char*)ms_addrStaticGameDocumentUsage) + 3)));

		INSERT_PADDING(16);
		csl::ut::FixedArray<GameObjectLayer*, 32> ObjectLayers{};
		csl::ut::ObjectMoveArray<GameObject*> Objects{ pAllocator };
		csl::ut::ObjectMoveArray<GameService*> Services{ pAllocator };
		INSERT_PADDING(32); // csl::ut::ObjectMoveArray<>
		INSERT_PADDING(32); // csl::ut::ObjectMoveArray<>
		csl::ut::ObjectMoveArray<GameManagerListener> ManagerListeners{ pAllocator };
		csl::ut::ObjectMoveArray<GameObjectListener> ObjectListeners{ pAllocator };
		csl::ut::ObjectMoveArray<ComponentListener> ComponentListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::ObjectMoveArray<>
		INSERT_PADDING(32); // csl::ut::ObjectMoveArray<>
		csl::ut::ObjectMoveArray<GameStepListener> StepListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::ObjectMoveArray<>
		INSERT_PADDING(192);
		GameApplication* pApplication{};

	public:
		inline static GameManager* GetSingleton()
		{
			return *ms_ppGameDocument;
		}

		GameService* GetService(const char* in_pServiceName)
		{
			for (auto* pService : Services)
			{
				if (pService == nullptr)
					continue;

				if (strcmp(pService->pStaticClass->pName, in_pServiceName) == 0)
					return pService;
			}

			return { nullptr };
		}

		template <typename T>
		T* GetService()
		{
			return static_cast<T*>(GetService(T::GetServiceName()));
		}

		GameObject* GetGameObject(const char* in_pObjectName)
		{
			for (auto* pObject : Objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->pObjectName, in_pObjectName) == 0)
					return pObject;
			}

			return { nullptr };
		}

		template <typename T>
		T* GetGameObject()
		{
			return static_cast<T*>(GetGameObject(T::GetObjectName()));
		}
	};
}

