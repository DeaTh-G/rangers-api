#pragma once

namespace hh::gfnd {
    class Renderable : public fnd::ReferencedObject {
    public:
        uint64_t unk1;
        csl::ut::LinkListNode renderableContainerNode;
        char preferredContainer;
        char unk4b;
        uint16_t unk5;
        const char* name;
        uint32_t unk6;
        uint64_t unk7;
        Renderable(csl::fnd::IAllocator* pAllocator);

        void SetUnk4(bool unkParam);
        void SetUnk5(uint16_t unkParam);

        virtual void UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() {}
        virtual bool UnkFunc3() { return true; }
    };
}
