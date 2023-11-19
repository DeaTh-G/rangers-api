#pragma once

namespace app::game {
    class ApplicationSequenceExtension
        : public ApplicationExtension
        , public hh::fnd::user::UserInfoEventListener
        , public hh::fw::FrameworkNotificationListener
    {
        hh::ut::TinyFsm<ApplicationSequenceExtension> fsm;
        GameMode* currentGameMode;
        hh::ut::TinyFsm<ApplicationSequenceExtension>::State_t state;
        // There's some big object here
        // char levelName[10];
        // uint8_t unk1;

    public:
        inline static const char* name = "ApplicationSequenceExtension";
        ApplicationSequenceExtension(csl::fnd::IAllocator* allocator);
        virtual uint64_t GetNameHash() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override {}
		virtual void GML_UnkFunc5() override;
        virtual void UIEL_UnkFunc1() override;
        virtual void FNL_UnkFunc4() override;

        inline GameMode* GetCurrentGameMode() {
            return currentGameMode;
        }
    };
}
