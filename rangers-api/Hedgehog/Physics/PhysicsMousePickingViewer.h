#pragma once

namespace hh::physics {

    class PhysicsMousePickingViewer
        : public PhysicsViewerBase
        , public PhysicsWorldListener
        , public fw::MouseEventHandler
        , public fw::ApplicationListener
    {
    public:
        struct Unk1 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;

            Unk1();
        };

        game::GameApplication* gameApplication;
        Unk1 unk201;
        uint8_t unk202;
        csl::ut::InplaceMoveArray<void*, 2> unk203;

        virtual int64_t UnkFunc5() override;
        virtual void PVCL_UnkFunc1() override;
        virtual void PVCL_UnkFunc2() override;
        virtual void PWL_UnkFunc2() override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk3() override;

        VIEWER_CLASS_DECLARATION(PhysicsMousePickingViewer)
    };
}
