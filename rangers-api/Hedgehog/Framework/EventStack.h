#pragma once

namespace hh::fw {
    class EventStack : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
    public:
        EventStack(csl::fnd::IAllocator* allocator, void* unkParam1, void* unkParam2);
    };
}
