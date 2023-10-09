#pragma once

namespace hh::game
{
	class GameManager : public hh::fnd::ReferencedObject
	{
	private:
		inline static void* ms_addrStaticGameDocumentUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameManager** ms_ppGameDocument = reinterpret_cast<GameManager**>(7 + (size_t)ms_addrStaticGameDocumentUsage + (*(int32_t*)(((char*)ms_addrStaticGameDocumentUsage) + 3)));

		INSERT_PADDING(280);
		csl::ut::ObjectMoveArray<GameObject*> Objects{ pAllocator };
		csl::ut::ObjectMoveArray<GameService*> Services{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::GameManagerListener> m_ManagerListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::GameObjectListener> m_ObjectListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::ComponentListener> m_ComponentListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		csl::ut::ObjectMoveArray<GameStepListener> StepListeners{ pAllocator };

		INSERT_PADDING(232);

	public:
		inline static GameManager* GetSingleton()
		{
			return *ms_ppGameDocument;
		}

		template <typename T>
		T* GetService()
		{
			for (auto* pService : Services)
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
		T* GetGameObject()
		{
			for (auto* pObject : Objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
					return reinterpret_cast<T*>(pObject);
			}

			return { nullptr };
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
	};
}

