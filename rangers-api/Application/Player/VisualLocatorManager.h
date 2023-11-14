#pragma once

namespace app::player {
    class GOCPlayerVisual;
    class VisualLocatorManager : public hh::fnd::ReferencedObject {
        GOCPlayerVisual* gocPlayerVisual;
        uint64_t unk1;
        uint64_t unk2;
        csl::math::Transform unk3;
        csl::math::Transform unk4;
        float unk5;
        float unk6;
        uint8_t unk7;
        csl::math::Transform unk8;
    public:
        VisualLocatorManager(csl::fnd::IAllocator* allocator, GOCPlayerVisual* gocPlayerVisual);
    };
}
