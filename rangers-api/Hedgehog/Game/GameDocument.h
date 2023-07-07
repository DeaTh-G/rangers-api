#pragma once

namespace app
{
	class GameDocument : public hh::fnd::ReferencedObject
	{
	private:
		inline static void* ms_addrStaticGameDocumentUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameDocument** ms_ppGameDocument = reinterpret_cast<GameDocument**>(7 + (size_t)ms_addrStaticGameDocumentUsage + (*(int32_t*)(((char*)ms_addrStaticGameDocumentUsage) + 3)));

		INSERT_PADDING(280);
		csl::ut::MoveArray<hh::game::GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<hh::game::GameService*> m_Services{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::GameManagerListener> m_ManagerListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::GameObjectListener> m_ObjectListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<hh::game::ComponentListener> m_ComponentListeners{ pAllocator };
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		INSERT_PADDING(32); // csl::ut::MoveArray<>
		csl::ut::MoveArray<hh::game::GameStepListener> m_StepListeners{ pAllocator };

		INSERT_PADDING(232);

	public:
		inline static GameDocument* GetSingleton()
		{
			return *ms_ppGameDocument;
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

		hh::game::GameService* GetService(const char* in_pServiceName)
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

		template <typename T>
		T* GetGameObject()
		{
			for (auto* pObject : m_Objects)
			{
				if (pObject == nullptr)
					continue;

				if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
					return reinterpret_cast<T*>(pObject);
			}

			return { nullptr };
		}

		hh::game::GameObject* GetGameObject(const char* in_pObjectName)
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
	};
}

