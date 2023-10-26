#pragma once

namespace app {
    class MyApplication : public hh::game::GameApplication {
        csl::ut::MoveArray<void*> unk201;
    public:
        MyApplication(csl::fnd::IAllocator* pAllocator, void* unkParam1);
        static MyApplication* Instantiate(void* unkParam1, csl::fnd::IAllocator* pAllocator);

        virtual void UnkFunc1();
        virtual void UnkFunc2();
        virtual void UnkFunc4();
        virtual void UnkFunc5();
        virtual uint64_t UnkFunc9();
    };
}
