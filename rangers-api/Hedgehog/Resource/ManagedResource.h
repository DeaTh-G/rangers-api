#pragma once

namespace hh::fnd {
    class ManagedResource;

    struct ManagedResourceClass {
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
        ManagedResourceClass* managedResourceClass;
        void* unk5;
        void* unk6;
        void* unk7;
        void* unk8;
        void* unk9;

    public:
        ManagedResource(csl::fnd::IAllocator* pAllocator);

        inline const char* GetName() {
            return name.c_str();
        }

        inline ManagedResourceClass& GetClass() {
            return *managedResourceClass;
        }

        virtual void UnkFunc1(void* unkParam) { this->UnkFunc2(unkParam); }
        virtual void UnkFunc2(void* unkParam) = 0;
        virtual void UnkFunc3() = 0;
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
    };
}
