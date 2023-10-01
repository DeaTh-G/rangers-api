#pragma once

namespace hh::game
{
    class GOComponentRegistry : fnd::BaseObject {
        class GOComponentRegistryItem {
        public:
            const char* name;
            GOComponentClass* componentClass;
            fnd::RflClass rflClass;
        };

        csl::ut::MoveArray<GOComponentRegistryItem*> components;
        csl::ut::StringMap<GOComponentRegistryItem*> componentsByName;
    public:
        GOComponentRegistry(csl::fnd::IAllocator* pAllocator);
        void LoadComponents(GOComponentRegistryItem** components);
    };
}
