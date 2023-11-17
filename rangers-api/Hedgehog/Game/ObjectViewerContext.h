#pragma once

namespace hh::game {
    class ObjectViewerContext
        : public dbg::ViewerContext
        , public GameViewerContextListener
        , public GameManagerListener
        , public GameObjectListener
    {
    public:
        uint64_t unk101;
        GameObject* selectedObject;
        uint64_t unk103;
        csl::ut::MoveArray<void*> listeners{ GetAllocator() };
    
        virtual void GVCL_UnkFunc1() override;
        virtual void GVCL_UnkFunc2() override;
		virtual void GML_UnkFunc2() override;
		virtual void GOL_UnkFunc2() override;

        VIEWER_CONTEXT_CLASS_DECLARATION(ObjectViewerContext)
    };
}
