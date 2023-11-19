#pragma once

namespace hh::game {
    class ObjectWorldChunkLayer : public fnd::ReferencedObject {
        uint8_t unk1;
        uint64_t unk2;
        ResObjectWorld* resource;
    public:
        ObjectWorldChunkLayer(csl::fnd::IAllocator* allocator, ResObjectWorld* resource);
        const char* GetName() const;
        void SetEnable(bool enabled);
    };
}
