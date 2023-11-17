#pragma once

namespace hh::physics {
    class PhysicsViewerContextListener {
    public:
        virtual ~PhysicsViewerContextListener() = default;
        virtual void PVCL_UnkFunc1() {}
        virtual void PVCL_UnkFunc2() {}
        virtual void PVCL_UnkFunc3() {}
    };

    class PhysicsViewerContext
        : public game::ServiceViewerContextBase
        , public PhysicsWorldListener
    {
    public:
        csl::ut::MoveArray<void*> unk201{ GetAllocator() };
        csl::ut::MoveArray<void*> unk202{ GetAllocator() };
        uint64_t unk203;
        csl::math::Vector4 unk204;
        csl::math::Vector4 unk205;
        uint32_t unk206;
        int unk207;
        uint8_t unk208;
        void* unk209; // object specific to this viewer that's created in the constructor
        csl::ut::VariableString unk210[32];
        uint64_t unk211;
    
        virtual void PWL_UnkFunc2() override;

        VIEWER_CONTEXT_CLASS_DECLARATION(PhysicsViewerContext)
    };
}
