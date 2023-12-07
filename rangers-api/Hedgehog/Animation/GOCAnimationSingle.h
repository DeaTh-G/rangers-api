#pragma once

namespace hh::anim {
    class AnimationManager;
    class GOCAnimationSingle : public GOCAnimation {
        uint64_t flags;
        AnimationManager* animationManager;
        uint64_t unk102;
        gfx::GOCVisualModel* visualModel;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint64_t unk107;
        uint64_t unk108;
        csl::ut::MoveArray<void*> unk109;
        uint64_t unk110;
        csl::ut::LinkListNode linkListNode;
    public:
        GOCAnimationSingle(csl::fnd::IAllocator* allocator);
        virtual void* GetClassId() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
    };
}
