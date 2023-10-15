#pragma once

namespace hh::hid {
    class UnknownListener {
        virtual void UL_UnkFunc1() {}
        virtual void UL_UnkFunc2() {}
        virtual void UL_UnkFunc3() {}
        virtual void UL_UnkFunc4() {}
    };

    class ActiveDeviceManagerListener {
        virtual void OnDeviceChange() = 0;
        virtual void ADML_UnkFunc2() = 0;
    };

    class ActiveDeviceManager : public fnd::ReferencedObject, public UnknownListener {
        struct Unk1 {
            char unk1;
            char unk2;
            char unk3;
        };

        uint32_t flags;
        csl::ut::InplaceMoveArray<Unk1, 8> unk1;
        csl::ut::InplaceMoveArray<void*, 4> unk2;
        csl::ut::InplaceMoveArray<void*, 4> unk3;
        void* unk4;
    public:
        ActiveDeviceManager(csl::fnd::IAllocator* pAllocator);
        void RegisterActiveDeviceManagerListener(ActiveDeviceManagerListener& listener);
        void UnregisterActiveDeviceManagerListener(ActiveDeviceManagerListener& listener);
    };
}
