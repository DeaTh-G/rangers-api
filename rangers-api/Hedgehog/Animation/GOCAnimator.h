#pragma once

namespace hh::anim {
    class GOCAnimator : public GOCAnimationSingle, public TriggerListener, public AnimationStateListener {
        AnimationStateMachine* animationStateMachine;
        AsmResourceManager* asmResourceManager;
        uint32_t unk203;
        char flags;
        char unk204b;
        uint64_t unk205;
    
    public:
        struct Config {
            uint16_t unk1;
            uint8_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            void* unk5;
            uint64_t unk6;
        };

        virtual void* GetClassId() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual bool UnkFunc1(csl::math::Transform& transform) override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual void TL_MaybeOnTrigger() override;
        virtual void ASL_MaybeOnStateChange() override;

        void SetAnimation(const char* animationName);

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimator)
    };
}
