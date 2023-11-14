#pragma once

namespace hh::anim {
    class GOCAnimator : public GOCAnimationSingle, public TriggerListener, public AnimationStateListener {
        uint64_t unk101;
        uint64_t unk102;
        uint32_t unk103;
        char unk104a;
        char unk104b;
        uint64_t unk105;
    
    public:
        virtual void TL_MaybeOnTrigger() override;
        virtual void ASL_MaybeOnStateChange() override;

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimator)
    };
}
