#pragma once

namespace hh::ui {
    class alignas(8) UIPanel : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> children;
    public:
        UIPanel(csl::fnd::IAllocator* pAllocator);
    };
}