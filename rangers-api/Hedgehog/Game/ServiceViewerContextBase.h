#pragma once

namespace hh::game {
    class ServiceViewerContextBase
        : public dbg::ViewerContext
        , public GameViewerContextListener
        , public GameManagerListener
    {
        uint64_t unk101;
        const GameServiceClass* gameServiceClass;
    public:
        ServiceViewerContextBase(csl::fnd::IAllocator* allocator, const GameServiceClass* gameServiceClass);

        virtual void GVCL_UnkFunc1() override;
        virtual void GVCL_UnkFunc2() override;
		virtual void GML_UnkFunc3() override;
		virtual void GML_UnkFunc4() override;
    };
}
