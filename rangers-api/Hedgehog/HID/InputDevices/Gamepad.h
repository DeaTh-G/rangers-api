#pragma once

namespace hh::hid {
    class Gamepad : public InputDevice {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::StringMap<void*> unk2;
        void* unk3;
        csl::ut::InplaceMoveArray<uint32_t, 32> unk4;
        char unk5[128];
        uint16_t unk6;
        float unk7;
    public:
        Gamepad(csl::fnd::IAllocator* pAllocator);
    };
}
