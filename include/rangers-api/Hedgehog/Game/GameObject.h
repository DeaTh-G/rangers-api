#pragma once

namespace hh::ui {
	class LayerController;
}

namespace hh::game
{
	class GameManager;
	class GameObject;

    class GameObjectClass {
    public:
        const char *pName;
        const char *pScopedName;
        uint64_t unk12;
        size_t objectSize;
        GameObject* (*instantiator)(csl::fnd::IAllocator* pAllocator);
        uint64_t unk15;
        uint64_t unk16;
        uint64_t unk17;
        uint32_t memberValueCount;
        hh::fnd::RflClassMember::Value* pMemberValues;
        hh::fnd::RflClass* reflectionClass;
	private:
		GameObject* Instantiate(csl::fnd::IAllocator* pAllocator) const;
	public:
		template<typename T>
		T* Instantiate(csl::fnd::IAllocator* pAllocator) const { return static_cast<T*>(Instantiate(pAllocator)); }
    };

	class GameObject : public fnd::Messenger
	{
		class Unk1 {
			GameObject* pGameObject;
			csl::ut::MoveArray<void*> unk27;
		};

		struct Unk2 {
			int64_t unk31;
			int64_t unk32;
			int64_t unk33;
			int64_t unk34;
		};

	public:
		enum class ComponentType : char {
			VISIBLE,
			PHYSICS,
			AUDIBLE,
		};

		enum class StatusFlags : char {
			DONT_PROCESS_MESSAGES = 0,
		};

		csl::ut::Bitset<StatusFlags> statusFlags;
		char layer{ 6 };
		csl::ut::Bitset<ComponentType> forceComponentsFlags;
		csl::ut::Bitset<ComponentType> componentsAreForcedOrNonEmptyFlags;
		char unk48;
		uint32_t m_VisualComponentsLengthWithUnk48InHiWord;
		uint32_t m_PhysicsComponentsLengthWithUnk48InHiWord;
		uint32_t m_AudibleComponentsLengthWithUnk48InHiWord;
		GameManager* pOwnerDocument{};

		void* unk54;
		//??GameObjectClass* pStaticClass{};

		GameObject(csl::fnd::IAllocator* pAllocator);
	private:
		csl::ut::InplaceMoveArray<GOComponent*, 8> m_Components;
		csl::ut::VariableString pObjectName;
		csl::ut::InplaceMoveArray<hh::fnd::Property, 2> m_Properties;
		csl::ut::MoveArray<void*> unk61;
		uint32_t m_ComponentFlags{};
		csl::ut::MoveArray<GOComponent*> m_VisualComponents;
		csl::ut::MoveArray<GOComponent*> m_PhysicsComponents;
		csl::ut::MoveArray<GOComponent*> m_AudibleComponents;
		csl::ut::MoveArray<void*> unk66;
		Unk1 unk67;
		void* unk68;
		GameObjectClass* pClass;
		Unk2 unk70;
		Unk2 unk71;
		Unk2 unk72;
		
		virtual void* GetClassId();
		virtual bool fUnk2(fnd::Message& message);
		virtual bool ProcessMessage(fnd::Message& message);
		virtual bool IsAcceptingMessages();
		virtual void Initialize(GameManager* gameManager) {}
		virtual void Dispose() {}
		virtual void Update(uint64_t unkParam, uint64_t unkParam2) {}
		virtual void UnkFunc9() {}
		virtual void UnkFunc10() {}
		virtual void UnkFunc11(uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4);

		// template <typename T>
		// T* GetGOC()
		// {
		// 	for (auto* pComponent : m_Components)
		// 	{
		// 		if (pComponent == nullptr)
		// 			continue;

		// 		if (strcmp(pComponent->pStaticClass->pName, T::GetComponentName()) == 0)
		// 			return reinterpret_cast<T*>(pComponent);
		// 	}

		// 	return { nullptr };
		// }

		hh::game::GOComponent* GetGOC(const char* in_pComponentName)
		{
			for (auto* pComponent : m_Components)
			{
				if (pComponent == nullptr)
					continue;

				if (strcmp(pComponent->pStaticClass->pName, in_pComponentName) == 0)
					return pComponent;
			}

			return { nullptr };
		}

		// template <typename T>
		// T* GetComponent()
		// {
		// 	return GetGOC<T>();
		// }

		hh::game::GOComponent* InstantiateComponent(GOComponentClass* gocClass);

		GOComponent* GetComponent(GOComponentClass* componentClass);
	protected:
		template<typename T>
		T* GetComponent() {
			return static_cast<T*>(GetComponent(T::GetClass()));
		}

		template<typename T>
		T* InstantiateComponent() {
			return static_cast<T*>(InstantiateComponent(T::GetClass()));
		}

		hh::game::GOComponent* GetComponent(const char* in_pComponentName)
		{
			return GetGOC(in_pComponentName);
		}

		void AttachComponent(GOComponent& component);
		void SetForceComponentsFlag(ComponentType type, bool enabled);

		/*
		 * Broadcasts a message to all the messengers registered in the associated LevelInfo.
		 */
		bool BroadcastMessage(fnd::Message& message);

		void SetLayer(char layer);

		void LinkActionToUIKey(ui::LayerController* layerController, const char* uiPath, const char* actionName, void* unkParam);
	};
}