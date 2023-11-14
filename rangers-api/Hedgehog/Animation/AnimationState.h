#pragma once

namespace hh::anim {
    class AnimationStateListener {
    public:
        virtual ~AnimationStateListener() = default;
        virtual void ASL_MaybeOnStateChange() = 0;
    };
}
