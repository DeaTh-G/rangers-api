#pragma once

namespace hh::game {
    class GameApplication : public fw::Application {
        void* unk101;
        void* unk102;

        static GameApplication* instance;
    public:
        GameApplication(csl::fnd::IAllocator* pAllocator, void* unkParam1);
        
        virtual void UnkFunc7();
        virtual void UnkFunc8();
        virtual uint64_t UnkFunc9();
        virtual void UnkFunc10() {}
    };
}
