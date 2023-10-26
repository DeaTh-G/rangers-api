#pragma once

namespace hh::fw {
    class Application : public hh::fnd::ReferencedObject, hh::fw::KeyEventHandler, hh::fw::MouseEventHandler {
        void* unkFromUnkParam1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;

        static Application* instance;
    public:
        Application(csl::fnd::IAllocator* pAllocator, void* unkParam1);

        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual uint64_t UnkFunc9() { return 0; }
    };
}
