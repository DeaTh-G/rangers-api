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
        virtual void* GetClassId() override;
        virtual uint64_t UnkFunc1() override;
        virtual float UnkFunc2() override;
        virtual void UnkFunc5() override;
        virtual bool UnkFunc7() override;
        virtual uint64_t UnkFunc8() = 0;
        virtual void UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual uint64_t UnkFunc11();
        virtual void UnkFunc12() {}
        virtual bool UnkFunc13() { return false; }
        virtual void UnkFunc14() {}
        virtual bool UnkFunc15() { return false; }
        virtual bool UnkFunc16() { return false; }
        virtual bool UnkFunc17() { return false; }
        virtual void UnkFunc18() {}
    };
}
