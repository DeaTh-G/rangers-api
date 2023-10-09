#pragma once

namespace hh::game
{
	class GameObject : public fnd::Messenger
	{
	public:
		INSERT_PADDING(24);
		GameManager* pManager{};

		INSERT_PADDING(8);
		//GameObjectClass* pStaticClass{};

	private:
		csl::ut::ObjectMoveArray<GOComponent*> Components{ pAllocator };

	public:
		INSERT_PADDING(64); // Even more Components 2nd and 3rd being GOCPlayerParameter and GOCPlayerBlackboard
		const char* pObjectName{};
		INSERT_PADDING(408);

		template <typename T>
		T* GetGOC()
		{
			for (auto* pComponent : Components)
			{
				if (pComponent == nullptr)
					continue;

				if (strcmp(pComponent->pStaticClass->pName, T::GetComponentName()) == 0)
					return reinterpret_cast<T*>(pComponent);
			}

			return { nullptr };
		}

		GOComponent* GetGOC(const char* in_pComponentName)
		{
			for (auto* pComponent : Components)
			{
				if (pComponent == nullptr)
					continue;

				if (strcmp(pComponent->pStaticClass->pName, in_pComponentName) == 0)
					return pComponent;
			}

			return { nullptr };
		}
	};
}