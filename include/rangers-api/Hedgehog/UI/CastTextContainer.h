#pragma once

namespace hh::ui {
    class CastTextContainer : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        UITextElement* textElement; // set in constructor, don't know what it is yet
    public:
        CastTextContainer(csl::fnd::IAllocator* pAllocator, UITextElement* textElement);
    };
}
