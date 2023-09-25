#pragma once

namespace hh::game
{

	class GameDocument : public hh::fnd::ReferencedObject
	{
		class Unk1 {
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

		class alignas(8) Layer : public hh::fnd::ReferencedObject
		{
			csl::ut::VariableString name;
			csl::ut::MoveArray<GameObject*> objects;
			uint32_t unk25;
		};

	private:
		inline static void* ms_addrStaticGameDocumentUsage = sigScan("\x48\x89\x2D\xCC\xCC\xCC\xCC\x8D\x75\x20", "xxx????xxx", (void*)0x14FE91CB8);
		inline static GameDocument** ms_ppGameDocument = reinterpret_cast<GameDocument**>(7 + (size_t)ms_addrStaticGameDocumentUsage + (*(int32_t*)(((char*)ms_addrStaticGameDocumentUsage) + 3)));

		void* unk32;
		uint32_t unk33;
		uint32_t unk34;
		void* unk35;
		csl::ut::FixedArray<Layer*, 32> m_Layers{};
		csl::ut::MoveArray<GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<GameService*> m_Services{ pAllocator };
		csl::ut::StringMap<GameService*> m_ServicesByName{ pAllocator };
		csl::ut::MoveArray<void*> unk40;
		csl::ut::MoveArray<void*> unk41; // csl::ut::MoveArray<GameManagerListener> m_ManagerListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk42; // csl::ut::MoveArray<GameObjectListener> m_ObjectListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk43; // csl::ut::MoveArray<ComponentListener> m_ComponentListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk44;
		csl::ut::MoveArray<void*> unk45;
		csl::ut::MoveArray<GameStepListener> m_StepListeners{ pAllocator };
		csl::ut::MoveArray<void*> unk47;
		csl::ut::MoveArray<void*> unk48;
		csl::ut::MoveArray<void*> unk49;
		void* unk50;
		uint32_t unk51;
		csl::ut::MoveArray<void*> unk52;
		Unk1 unk53;
		void* unk54;
		uint32_t unk55;
		void* unk56;

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

