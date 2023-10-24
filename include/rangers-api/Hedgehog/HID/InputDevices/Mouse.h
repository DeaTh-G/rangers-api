#pragma once

namespace hh::hid {
    class Mouse : public InputDevice {
        bool unk1;
        uint16_t unk2;
        uint16_t unk3;
        uint16_t unk4;
        uint16_t unk5;
        uint16_t unk6;
        bool unk7;
        csl::ut::InplaceMoveArray<uint32_t, 13> unk8;
    public:
        Mouse(csl::fnd::IAllocator* pAllocator);
    };
}
