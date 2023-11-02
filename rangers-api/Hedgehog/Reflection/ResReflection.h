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

        virtual void UnkFunc2(void* unkParam, uint64_t unkParam2) override;
        virtual void UnkFunc3() override;
    };
}
