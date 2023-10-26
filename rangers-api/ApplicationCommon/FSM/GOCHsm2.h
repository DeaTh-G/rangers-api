#pragma once

namespace app_cmn::fsm {
    class GOCHsm2 : public hh::game::GOComponent {
        uint64_t unk101;
        hh::ut::HsmBase hsm;
        int64_t unk102;
        bool unk103;
        uint32_t unk104;
        csl::ut::InplaceMoveArray<void*, 1> unk105;
        uint64_t unk106;
        uint64_t unk107;
    public:
        GOCHsm2(csl::fnd::IAllocator* pAllocator);
        static GOCHsm2* Instantiate(csl::fnd::IAllocator* pAllocator);
    };
}
