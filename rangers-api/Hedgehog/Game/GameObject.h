#pragma once

namespace hh::game
{
	class GameDocument;
	class GameObject;

    class GameObjectClass {
    public:
        const char *pName;
        const char *pScopedName;
        UNKNOWN(uint64_t);
        size_t objectSize;
        GameObject* (*Instantiate)(csl::fnd::IAllocator* pAllocator);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
    };

	class GameObject : public fnd::Messenger
	{
		class Unk1 {
			GameObject* pGameObject;
			UNKNOWN(csl::ut::MoveArray<void*>);
		};

		struct Unk2 {
			UNKNOWN(int64_t);
			UNKNOWN(int64_t);
			UNKNOWN(int64_t);
			UNKNOWN(int64_t);
		};

	public:
		UNKNOWN(char);
		UNKNOWN(char);
		UNKNOWN(char);
		UNKNOWN(char);
		UNKNOWN(char);
		UNKNOWN(void*);
		UNKNOWN(uint32_t);
		GameDocument* pOwnerDocument{};

		UNKNOWN(void*);
		//??GameObjectClass* pStaticClass{};

	private:
		csl::ut::InplaceMoveArray<GOComponent*, 8> m_Components;
		csl::ut::VariableString pObjectName;
		csl::ut::InplaceMoveArray<hh::fnd::Property, 2> m_Properties;
		UNKNOWN(csl::ut::MoveArray<void*>);
		uint32_t m_ComponentFlags{};
		csl::ut::MoveArray<GOComponent> m_VisualComponents;
		csl::ut::MoveArray<GOComponent> m_PhysicsComponents;
		csl::ut::MoveArray<GOComponent> m_AudibleComponents;
		UNKNOWN(csl::ut::MoveArray<void*>);
		UNKNOWN(Unk1);
		UNKNOWN(void*);
		GameObjectClass* pClass;
		UNKNOWN(Unk2);
		

		template <typename T>
		T* GetGOC()
		{
			for (auto* pComponent : m_Components)
			{
				if (pComponent == nullptr)
					continue;

				if (strcmp(pComponent->pStaticClass->pName, T::GetComponentName()) == 0)
					return reinterpret_cast<T*>(pComponent);
			}

			return { nullptr };
		}

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

		template <typename T>
		T* GetComponent()
		{
			return GetGOC<T>();
		}

		hh::game::GOComponent* GetComponent(const char* in_pComponentName)
		{
			return GetGOC(in_pComponentName);
		}

		hh::game::GOComponent* InstantiateComponent(const GOComponentClass& componentClass);
	};
}