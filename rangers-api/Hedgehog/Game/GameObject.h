#pragma once

namespace hh::game
{
	class GameObject : public fnd::Messenger
	{
	public:
		INSERT_PADDING(24);
		app::GameDocument* pDocument{};

		INSERT_PADDING(8);
		//GameObjectClass* pStaticClass{};

	private:
		csl::ut::MoveArray<GOComponent*> m_Components{ pAllocator };

	public:
		INSERT_PADDING(64); // Even more Components 2nd and 3rd being GOCPlayerParameter and GOCPlayerBlackboard
		const char* pObjectName{};
		INSERT_PADDING(408);

		template <typename T>
		T* GetComponent()
		{
			for (auto* pComponent : m_Components)
				if (strcmp(pComponent->pStaticClass->pName, T::GetComponentName()) == 0)
					return reinterpret_cast<T*>(pComponent);

			return { nullptr };
		}
	};
}