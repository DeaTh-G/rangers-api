#pragma once

namespace hh::hid {
    class Keyboard : public InputDevice {
        uint16_t unk1;
        csl::ut::InplaceMoveArray<uint32_t, 16> unk3;
        csl::ut::InplaceMoveArray<uint32_t, 4> unk4;
        char unk5[256];
    public:
        Keyboard(csl::fnd::IAllocator* pAllocator);
    };
}
