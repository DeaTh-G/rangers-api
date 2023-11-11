#pragma once

namespace app::gfx {
    class FxParamExtension : public hh::fnd::BaseObject {

    };

    class FxParamManager
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public app::game::GameCondition::Listener {
    public:
        class InterpolatorBase : public hh::fnd::ReferencedObject {
        public:
            InterpolatorBase(csl::fnd::IAllocator* allocator);
        };

        template<typename T>
        class Interpolator : public InterpolatorBase {
            struct Unk1 {
                T parameters;
                uint64_t owner;
                uint32_t wantsToInterpolateGroupBits;
                float unk3;
                float delta;
                float unk5;
                uint32_t unk6;
                uint32_t unk7; // not sure if exists
            };
        public:
            T* target;
            void (*interpolationFunction)(T* target, T* lower, T* upper, unsigned int flags, float delta);
            csl::ut::InplaceMoveArray<Unk1, 4> interpolationActors;
            uint32_t interpolationGroupEnabledBits; // bit nr = index of group
            uint32_t interpolationGroupCount;
            Interpolator(csl::fnd::IAllocator* allocator, T* target);
        };

        struct NeedleFXSceneConfigInterpolators {
            Interpolator<app::rfl::FxRenderTargetSetting>* fxRenderTargetSettingInterpolator;
            Interpolator<app::rfl::FxAntiAliasing>* fxAntiAliasingInterpolator;
            Interpolator<app::rfl::StageCommonAtmosphereParameter>* stageCommonAtmosphereParameterInterpolator;
            Interpolator<app::rfl::FxLODParameter>* fxLODParameterInterpolator;
            Interpolator<app::rfl::FxDetailParameter>* fxDetailParameterInterpolator;
            Interpolator<app::rfl::FxDynamicResolutionParameter>* fxDynamicResolutionParameterInterpolator;
            Interpolator<app::rfl::StageCommonTimeProgressParameter>* stageCommonTimeProgressParameterInterpolator;
        };

        struct Unk3 {
            uint64_t unk1;
            uint64_t unk2;
        };

        app::rfl::NeedleFxParameter parameters;
        app::rfl::NeedleFxSceneConfig sceneConfig;
        InterpolatorBase* interpolators[40];
        NeedleFXSceneConfigInterpolators unk103;
        Unk3 unk104;
        csl::ut::MoveArray<FxParamExtension*> extensions;
        uint32_t unk106;
        csl::fnd::Mutex mutex;
        uint16_t unk107;
        uint8_t unk108;

    public:
        FxParamManager(csl::fnd::IAllocator* allocator);

		GAMESERVICE_CLASS_DECLARATION
    };
}
