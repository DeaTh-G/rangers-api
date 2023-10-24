#pragma once

namespace hh::hid {
    class DeviceManager : public fnd::BaseObject {
        csl::ut::MoveArray<InputDevice*> inputDevices;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        uint32_t unk4; // 8 nibbles with initial values going from 0 to 7
        InputDevice* unk5;
        InputDevice* unk6;
        uint64_t unk7;
        ActiveDeviceManager* activeDeviceManager;
        InputDeviceFactory inputDeviceFactory;
    public:
        DeviceManager(csl::fnd::IAllocator* pAllocator);
        ActiveDeviceManager* GetActiveDeviceManager();
    };
}
