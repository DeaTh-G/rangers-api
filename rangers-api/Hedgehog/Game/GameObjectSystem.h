#pragma once

namespace hh::game {
    class GameObjectSystem : public fnd::BaseObject {
        class GOComponentReference {
            const char* name;
            GOComponentClass* componentClass;
            fnd::RflClass* reflectionClass;
        };

        csl::fnd::IAllocator* pHeapAllocator;
        fnd::ThreadSafeTlsfHeapAllocator heapAllocator;
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;
        fnd::CollectionTemplate<GameObjectClass> objClasses;
        fnd::CollectionTemplate<GOComponentReference> objInfos;
    };
}