#pragma once

namespace hh::game
{
    class GOComponentRegistry : fnd::BaseObject {
    public:
        class GOComponentRegistryItem {
        public:
            const char* name;
            const GOComponentClass* componentClass;
            const fnd::RflClass* rflClass;
        };
    private:
        csl::ut::MoveArray<GOComponentRegistryItem*> components;
        csl::ut::StringMap<GOComponentRegistryItem*> componentsByName;
    public:
        GOComponentRegistry(csl::fnd::IAllocator* pAllocator);
        void LoadComponents(GOComponentRegistryItem** components);
        const GOComponentRegistryItem* GetComponentInformationByName(const char* name);
    };

    struct GOComponentConfiguration {
        GOComponentRegistry::GOComponentRegistryItem* component;
        void* data;
    };
}
