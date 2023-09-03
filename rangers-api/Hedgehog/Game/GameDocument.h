#pragma once

namespace hh::game
{

	class GameDocument : public hh::fnd::ReferencedObject
	{
		class Unk1 {
			class Unk2 {
				UNKNOWN(void*);
				UNKNOWN(void*);
				UNKNOWN(void*);
			};

			UNKNOWN(void*);
			UNKNOWN(Unk2);
			UNKNOWN(Unk2);
			UNKNOWN(uint32_t);
		};

		class alignas(8) Layer : public hh::fnd::ReferencedObject
		{
			csl::ut::VariableString name;
			csl::ut::MoveArray<GameObject*> objects;
			UNKNOWN(uint32_t);
		};

	private:
		inline static void* ms_addrStaticGameDocumentUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameDocument** ms_ppGameDocument = reinterpret_cast<GameDocument**>(7 + (size_t)ms_addrStaticGameDocumentUsage + (*(int32_t*)(((char*)ms_addrStaticGameDocumentUsage) + 3)));

		UNKNOWN(void*);
		UNKNOWN(uint32_t);
		UNKNOWN(uint32_t);
		UNKNOWN(void*);
		csl::ut::FixedArray<Layer*, 32> m_Layers{};
		csl::ut::MoveArray<GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<GameService*> m_Services{ pAllocator };
		csl::ut::StringMap<GameService*> m_ServicesByName{ pAllocator };
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(csl::ut::MoveArray<void*>); // csl::ut::MoveArray<GameManagerListener> m_ManagerListeners{ pAllocator };
		UNKNOWN(csl::ut::MoveArray<void*>); // csl::ut::MoveArray<GameObjectListener> m_ObjectListeners{ pAllocator };
		UNKNOWN(csl::ut::MoveArray<void*>); // csl::ut::MoveArray<ComponentListener> m_ComponentListeners{ pAllocator };
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(csl::ut::MoveArray<void*>);
		csl::ut::MoveArray<GameStepListener> m_StepListeners{ pAllocator };
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(void*);
		UNKNOWN(uint32_t);
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(Unk1);
		UNKNOWN(void*);
		UNKNOWN(uint32_t);
		UNKNOWN(void*);

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
	};
}

