#pragma once

namespace hh::game {
    class ObjectWorldChunk;
    class ObjectWorldChunkLayer : public fnd::ReferencedObject {
        enum class Flag : uint8_t {
            ENABLED,
        };

        csl::ut::Bitset<Flag> flags;
        ObjectWorldChunk* chunk;
        ResObjectWorld* resource;
    public:
        ObjectWorldChunkLayer(csl::fnd::IAllocator* allocator, ResObjectWorld* resource);
        const char* GetName() const;
        inline ResObjectWorld* GetResource() {
            return resource;
        }
        void SetEnable(bool enabled);
        bool IsEnable() const;
    };
}
