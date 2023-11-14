#pragma once

namespace app::player {
    class GOCPlayerVisual;
    class PlayerVisual : public hh::fnd::ReferencedObject {
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        void* unkFromUnkParam1;
        uint64_t unk1;
        uint16_t unk2;
    public:
        PlayerVisual(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, void* unkParam1);
    };
}