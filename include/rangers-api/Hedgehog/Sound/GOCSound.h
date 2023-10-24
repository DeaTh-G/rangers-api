#pragma once

namespace hh::snd {
    class GOCSound : public game::GOComponent {
        uint64_t unk101;
        uint64_t unk102;
        uint32_t unk103;
        csl::ut::MoveArray<void*> unk104;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
    
        static GOCSound* Instantiate(csl::fnd::IAllocator* pAllocator);
    public:
        struct alignas(8) Config {
            uint32_t unk1a;
            uint32_t unk1b;
            uint32_t unk2;
            bool unk3;
        };

        void Initialize(const Config& config);
    };
}