#pragma once

namespace hh::anim {
    class AnimationStateListener {
    public:
        virtual ~AnimationStateListener() = default;
        virtual void ASL_MaybeOnStateChange() = 0;
    };

    class AnimationStateMachine : public fnd::ReferencedObject {
        csl::ut::InplaceMoveArray<csl::math::Matrix44, 4> unk1;
        uint8_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk4b;
        csl::ut::InplaceMoveArray<csl::math::Transform, 1> unk5;
        csl::ut::InplaceMoveArray<void*, 1> unk6;
        csl::ut::InplaceMoveArray<void*, 1> unk7;
        csl::ut::InplaceMoveArray<void*, 1> unk8;
        uint64_t unk9;
        csl::ut::MoveArray<void*> unk10;
        uint64_t unk10b;
        csl::ut::MoveArray<void*> unk11;
        uint32_t unk12;
        float unk13;
        csl::math::Transform transform;
        uint8_t unk14;
        uint8_t unk14b;
        uint8_t unk15;

    public:
        AnimationStateMachine(csl::fnd::IAllocator* allocator);
        bool SetAnimation(const char* animationName);
    };
}
