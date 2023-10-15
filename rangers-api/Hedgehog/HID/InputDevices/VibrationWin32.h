#pragma once

namespace hh::hid {
    class VibrationWin32 : public Vibration {
        int64_t unk101;
        uint32_t unk102;
    public:
        VibrationWin32(csl::fnd::IAllocator* pAllocator);
        static VibrationWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
