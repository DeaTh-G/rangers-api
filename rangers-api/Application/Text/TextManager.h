#pragma once

namespace app::text {
    class TextManager
        : public hh::game::GameService
        , public hh::fnd::ResourceManager::ResourceListener
        , public hh::game::ErrorViewerListener
        , public app::fnd::AppResourceManagerListener
    {
        void* unk101;
        void* unk102;
        void* unk103;
        hh::text::TagReplacer* tagReplacer;
        void* unk104;

        virtual void RL_UnkFunc1(hh::fnd::ManagedResource* resource) override;
        virtual void RL_UnkFunc2(void* unkParam1) override;
        virtual void EVL_UnkFunc2(int unkParam1, int unkParam2, int& unkParam3) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;

    private:
        static hh::game::GameServiceClass gameServiceClass;
        static hh::game::GameService* Instantiate(csl::fnd::IAllocator* pAllocator);
        
    public:
        static hh::game::GameServiceClass* GetClass();
    };
}
