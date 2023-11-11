#pragma once

namespace hh::gfx {
    class NeedleRenderer : public needle::Renderable {
        fnd::Reference<gfnd::RenderableContainer> renderableContainer;
    public:
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
    };
}
