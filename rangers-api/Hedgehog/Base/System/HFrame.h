#pragma once

namespace hh::fnd {
    class HFrame : public ReferencedObject {
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint16_t unk6;
        uint64_t unk8;
        int unk7;
        void* unk9;
        void* unk10;
        csl::ut::InplaceMoveArray<void*, 10> unk11;
        csl::math::Vector4 unk12;
        csl::math::Vector4 unk13;
        csl::math::Vector4 unk14;
        csl::math::Vector4 unk15;
        csl::math::Vector4 unk16;
        csl::math::Vector4 unk17;
    public:
        HFrame(csl::fnd::IAllocator* allocator);
    };
}
