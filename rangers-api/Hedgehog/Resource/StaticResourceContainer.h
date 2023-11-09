#pragma once

namespace hh::fnd {
    class StaticResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        void* unk2;
        csl::ut::MoveArray<ManagedResource*> resources;
    public:
        StaticResourceContainer(csl::fnd::IAllocator* allocator);
        const ResourceTypeInfo* GetTypeInfo() {
            return typeInfo;
        }

        virtual void* GetFamilyID() override;
        virtual ManagedResource* GetResourceByName(const char* name) const override;
        virtual int GetNumResources() const override;
        virtual void UnkFunc1() override;
        virtual ManagedResource* GetResourceByIndex(int index) const override;
    };
}
