#pragma once

namespace hh::game {
    class GameApplication : public fw::Application {
        fnd::Reference<GameManager> gameManager;
        fnd::Reference<GameUpdater> gameUpdater;

    public:
        static GameApplication* instance;

        inline static GameApplication* GetInstance() {
            return RESOLVE_STATIC_VARIABLE(instance);
        }

        GameApplication(csl::fnd::IAllocator* pAllocator, void* unkParam1);
        
        inline GameUpdater& GetGameUpdater() const {
            return gameUpdater;
        }

        virtual void UnkFunc7();
        virtual void UnkFunc8();
        virtual uint64_t UnkFunc9();
        virtual void UnkFunc10() {}
    };
}
