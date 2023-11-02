#pragma once

namespace hh::fnd {
    class Packfile : public ManagedResource {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> resourceContainers;
        csl::ut::PointerMap<ResourceTypeInfo*, int> resourceIdByClass;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::VariableString unk5;
        csl::ut::MoveArray<void*> unk6;

        Packfile(csl::fnd::IAllocator* pAllocator);
        static ManagedResource* Instantiate(csl::fnd::IAllocator* pAllocator);
    public:
        virtual void UnkFunc2(void* unkParam, uint64_t unkParam2) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc6(void* unkParam) {}
        
        ManagedResource* GetResourceByName(const char* name, const ResourceTypeInfo* typeInfo);
        const char* GetResourceIDName(int resourceId, const ResourceTypeInfo* typeInfo);
    };
}
