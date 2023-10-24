#pragma once

namespace hh::hid {
    class PointingWin32 : public Pointing {
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };
        csl::ut::InplaceMoveArray<Unk1, 1> unk1;
    public:
        PointingWin32(csl::fnd::IAllocator* pAllocator);
        static PointingWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
