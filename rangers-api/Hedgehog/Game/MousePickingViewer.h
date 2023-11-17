#pragma once

namespace hh::game {
    class MousePickingViewer
        : public GameViewerBase
        , public GameManagerListener
        , public fw::MouseEventHandler
        , public fw::ApplicationListener
    {
        GameApplication* application;
        csl::ut::MoveArray<GameObject*> selectableObjects;
    public:
        fnd::Reference<ObjectViewerContext> objectViewerContext;
        
        virtual void GVCL_UnkFunc1() override;
        virtual void GVCL_UnkFunc2() override;
		virtual void GML_UnkFunc1() override;
		virtual void GML_UnkFunc2() override;
        virtual bool MEH_Unk2() override;
        virtual void AL_UnkFunc1() override;
    
        VIEWER_CLASS_DECLARATION(MousePickingViewer)
    };
}
