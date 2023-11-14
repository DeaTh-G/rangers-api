#pragma once

namespace hh::fnd {
    template<typename T>
    class ResReflection;

    template<>
    class ResReflection<void> : public ManagedResource {
    public:
        void* reflectionData;
        uint64_t unk1;
        uint64_t unk2;

        static const ResourceTypeInfo* GetTypeInfo();

        void* GetData();
    };

    template<typename T>
    class ResReflection : public ManagedResource {
    public:
        T* reflectionData;
        uint64_t unk1;
        uint64_t unk2;

        T* GetData() {
            return static_cast<T*>(reinterpret_cast<ResReflection<void>>(this)->GetData());
        }

        inline static ResourceTypeInfo* GetTypeInfo() {
            return ResReflection<void>::GetTypeInfo();
        }

        virtual void Load(void* data, size_t size) override;
        virtual void Unload(void* data, size_t size) override;
    };
}
