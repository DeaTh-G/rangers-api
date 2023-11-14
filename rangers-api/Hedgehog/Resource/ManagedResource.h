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

    class StaticResourceContainer;
    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
        csl::ut::VariableString name;
        csl::ut::VariableString unk2;
        csl::ut::VariableString unk3;
        const ResourceTypeInfo* resourceTypeInfo;
        void* unk5;
        void* unk6;
        void* binaryData;
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

        // This is only guessed from a similar function in rio, but there this and the following function are swapped.
        // I haven't actually seen this be overridden anywhere.
        virtual void Load(void* data, size_t size, StaticResourceContainer* container) { this->Load(data, size); }
        virtual void Load(void* data, size_t size) = 0;
        virtual void Unload(void* data, size_t size) = 0;
        virtual void Resolve(ResourceResolver* resolver) {}
        virtual void Reload(void* data, size_t size) {}
    };
}
