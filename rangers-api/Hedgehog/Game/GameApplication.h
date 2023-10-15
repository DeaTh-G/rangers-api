#pragma once

namespace hh::game {
    class GameApplication : public fw::Application {
        static GameApplication* instance;
    public:
        GameApplication(csl::fnd::IAllocator* pAllocator);
        
        virtual void UnkFunc7();
        virtual void UnkFunc8();
        virtual uint64_t UnkFunc9();
        virtual void UnkFunc10() {}
    };
}
