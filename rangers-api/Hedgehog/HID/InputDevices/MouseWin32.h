#pragma once

namespace hh::hid {
    class MouseWin32 : public Mouse, public hh::fw::MouseEventHandler {
        uint32_t unk101;
        uint32_t unk102;
        uint32_t unk103;
        uint16_t unk104;
        uint32_t unk105;
        uint16_t unk106;
        uint8_t unk107;
        uint64_t unk108;
        uint64_t unk109;
        csl::math::Vector4 unk112;
        uint64_t unk110;
        uint64_t unk111;
        uint64_t unk113;
    public:
        MouseWin32(csl::fnd::IAllocator* pAllocator);
        static MouseWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
