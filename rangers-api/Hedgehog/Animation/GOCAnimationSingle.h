#pragma once

namespace hh::anim {
    class GOCAnimationSingle : public GOCAnimation {
        uint64_t flags;
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint64_t unk107;
        uint64_t unk108;
        csl::ut::MoveArray<void*> unk109;
        uint64_t unk110;
        uint64_t unk111;
        uint64_t unk112;
    public:
        GOCAnimationSingle(csl::fnd::IAllocator* allocator);
    };
}
