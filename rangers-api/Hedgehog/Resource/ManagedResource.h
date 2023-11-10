#pragma once

namespace hh::fnd {
    class ManagedResource;

    struct ResourceTypeInfo {
        const char *pName;
        const char *pScopedName;
        uint32_t objectSize;
        uint32_t unk1;
        ManagedResource* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
        csl::ut::VariableString name;
        csl::ut::VariableString unk2;
        csl::ut::VariableString unk3;
        const ResourceTypeInfo* resourceTypeInfo;
        void* unk5;
        void* unk6;
        void* unk7;
        size_t size;
        void* unk8;

    public:
        ManagedResource(csl::fnd::IAllocator* pAllocator);

        inline const char* GetName() const {
            return name.c_str();
        }

        inline const ResourceTypeInfo& GetClass() const {
            return *resourceTypeInfo;
        }

        inline size_t GetSize() const {
            return size;
        }

        virtual void UnkFunc1(void* unkParam, uint64_t unkParam2) { this->UnkFunc2(unkParam, unkParam2); }
        virtual void UnkFunc2(void* unkParam, uint64_t unkParam2) = 0;
        virtual void UnkFunc3() = 0;
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
    };
}
