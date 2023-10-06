#pragma once

namespace app::player {
    template<typename T>
    class GOCPlayerStateBase : public hh::ut::StateBase<T> {
        struct Unk1 {
            uint64_t a;
            uint64_t b;
        };
    public:
        uint64_t unk2;
        uint64_t unk3;
        csl::ut::MoveArray<void*> unk1;
        uint64_t unk4;
        csl::ut::InplaceMoveArray<Unk1, 3> unk5;
        uint64_t unk9;
        uint32_t unk10;
        int32_t unk11;
    };
}