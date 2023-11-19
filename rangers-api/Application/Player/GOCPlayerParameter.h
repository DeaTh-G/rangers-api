#pragma once

namespace app::player {
    class GOCPlayerParameter : public hh::game::GOComponent {
    public:
        union CharacterParameters {
            hh::fnd::ResReflection<app::rfl::SonicParameters> sonic;
            hh::fnd::ResReflection<app::rfl::AmyParameters> amy;
            hh::fnd::ResReflection<app::rfl::KnucklesParameters> knuckles;
            hh::fnd::ResReflection<app::rfl::TailsParameters> tails;
        };

        union CharacterModePackage {
            app::rfl::ModePackageSonic sonic;
            app::rfl::ModePackageAmy amy;
            app::rfl::ModePackageKnuckles knuckles;
            app::rfl::ModePackageTails tails;
            app::rfl::ModePackage unknown;
        };

        union CharacterCommonModePackage {
            app::rfl::CommonPackageSonic sonic;
            app::rfl::CommonPackageAmy amy;
            app::rfl::CommonPackageKnuckles knuckles;
            app::rfl::CommonPackageTails tails;
            app::rfl::CommonPackage unknown;
        };

        hh::fnd::Reference<CharacterParameters> characterParameters;
        hh::fnd::Reference<hh::fnd::ResReflection<app::rfl::PlayerCameraSetParameters>> cameraSetParameters;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        uint32_t mode;
        uint32_t unk9;
        CharacterId characterId;
        uint64_t unk10[28];

    private:
        void* GetPlayerParameter(const hh::fnd::RflClass& rflClass);
    public:
        struct Config {
            uint32_t flags;
            hh::fnd::Reference<hh::fnd::ResReflection<CharacterParameters>> characterParameters;
            hh::fnd::Reference<hh::fnd::ResReflection<app::rfl::PlayerCameraSetParameters>> cameraSetParameters;
            CharacterId characterId;
        };

        GOCPlayerParameter(csl::fnd::IAllocator* allocator);
        void Initialize(const Config& config);

        app::rfl::PlayerParamSpeed& GetSpeedParameters();

        template<typename T>
        T* GetPlayerParameter() {
            return reinterpret_cast<T*>(GetPlayerParameter(RESOLVE_STATIC_VARIABLE(T::staticClass)));
        }

        // template<typename T>
        // T* GetPlayerParameter(const hh::fnd::RflClass& rflClass) {
        //     return reinterpret_cast<T*>(GetPlayerParameter(rflClass));
        // }

        virtual void* GetClassId() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerParameter)
    };
}
