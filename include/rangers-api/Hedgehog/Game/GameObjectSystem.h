#pragma once

namespace hh::game {
    class GameObjectSystem : public fnd::BaseObject, public csl::fnd::Singleton<GameObjectSystem> {
        class GOComponentReference {
            const char* name;
            GOComponentClass* componentClass;
            fnd::RflClass* reflectionClass;
        };

        csl::fnd::IAllocator* pHeapAllocator;
        fnd::ThreadSafeTlsfHeapAllocator heapAllocator;
        GameObjectRegistry* pGameObjectRegistry;
        GOComponentRegistry* pGOComponentRegistry;

        static fnd::HandleManager* handleManager;
    public:
        GameObjectSystem(csl::fnd::IAllocator* pAllocator);

        // Fully inlined in Frontiers
        void Initialize();

        static void LoadGameObjectClasses();
    };
}
