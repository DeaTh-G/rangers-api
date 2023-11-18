#pragma once

namespace hh::physics {
    class GOCCollider : public game::GOComponent, public fnd::HFrame::Listener {
        uint64_t pad; // probably some of the next data is actually one big block that's 16 aligned
        uint64_t unk101;
        fnd::HFrame* frame;
        fnd::HFrame* frame2;
        fnd::WorldPosition worldPos1;
        fnd::WorldPosition worldPos2;
        csl::math::Vector3 maybeScale;
        char unk104;
        bool unk104b;
        uint16_t unk105;
        uint16_t unk105b;
        uint64_t unk106;
        uint32_t unk107;
        PhysicsWorldBullet* physicsWorld;
        csl::ut::InplaceMoveArray<void*, 1> unk109; // incorrect, the inner obj here is actually 2 floats
        csl::ut::MoveArray<void*> unk110;
        uint64_t unk111;
        float unk112;
        float unk113;
    public:
        GOCCollider(csl::fnd::IAllocator* allocator);
    };
}
