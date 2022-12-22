#pragma once

namespace hh::game
{
	class GameObject;
}

namespace app
{
	class GameDocument : public hh::fnd::ReferencedObject
	{
	private:
		inline static GameDocument** ms_ppGameDocument = reinterpret_cast<GameDocument**>(0x143B335C8);

		INSERT_PADDING(280);
		csl::ut::MoveArray<hh::game::GameObject*> m_Objects{ pAllocator };
		csl::ut::MoveArray<hh::game::GameService*> m_Services{ pAllocator };
		INSERT_PADDING(488);

	public:
		inline static GameDocument* GetSingleton()
		{
			return *ms_ppGameDocument;
		}

		template <typename T>
		T* GetService()
		{
			for (auto* pService : m_Services)
				if (strcmp(pService->pStaticClass->pName, T::GetServiceName()) == 0)
					return reinterpret_cast<T*>(pService);
		
			return { nullptr };
		}

		template <typename T>
		T* GetGameObject()
		{
			for (auto* pObject : m_Objects)
				if (strcmp(pObject->pObjectName, T::GetObjectName()) == 0)
					return reinterpret_cast<T*>(pObject);

			return { nullptr };
		}
	};
}

