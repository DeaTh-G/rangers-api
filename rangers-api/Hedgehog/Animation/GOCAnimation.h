#pragma once

namespace hh::anim {
    class GOCAnimation : public game::GOComponent {
    public:
        GOCAnimation(csl::fnd::IAllocator* allocator);
        virtual bool UnkFunc1(csl::math::Transform& transform) { return false; }
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual uint64_t UnkFunc4() = 0;
    };
}
