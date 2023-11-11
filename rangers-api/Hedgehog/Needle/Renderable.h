#pragma once

namespace hh::needle {
    class Renderable : public NeedleRefcountObject {
    public:
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
    };
}
