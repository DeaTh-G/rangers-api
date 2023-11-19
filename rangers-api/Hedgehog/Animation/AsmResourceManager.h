#pragma once

namespace hh::anim {
    class AsmResourceManager : public fnd::ReferencedObject {
        fnd::Reference<ResAnimator> asmResource;
        uint64_t unk0b;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        float unk6;
        uint8_t unk7;
    public:
        struct Config {
            ResAnimator* animatorResource;
            const char* animatorName; // defninitely not correct
        };

        AsmResourceManager(csl::fnd::IAllocator* allocator);
        void Setup(const Config& config);
    };
}
