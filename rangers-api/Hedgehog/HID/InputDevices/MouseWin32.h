#pragma once

namespace hh::hid {
    class MouseWin32 : public Mouse, public hh::fw::MouseEventHandler {
    public:
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
        MouseWin32(csl::fnd::IAllocator* pAllocator);
        static MouseWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
        virtual void* GetClassId() override;
        virtual void UnkFunc5() override;
        virtual uint64_t UnkFunc8() override;
        virtual void UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual void UnkFunc12() override;
        virtual void UnkFunc14() override;
        virtual bool UnkFunc15() override;
        virtual bool UnkFunc16() override;
        virtual bool UnkFunc17() override;
        virtual void UnkFunc18() override;
    };
}
