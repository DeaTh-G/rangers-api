
#pragma once

namespace hh::ui {
    class SurfRideProjectContext : public fnd::ReferencedObject {
        csl::ut::VariableString unk1;
        csl::ut::MoveArray<void*> unk2;
    public:
        SurfRideProjectContext(csl::fnd::IAllocator* pAllocator);
    };
}
