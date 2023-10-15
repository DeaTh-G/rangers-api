#pragma once

namespace hh::ui {
    class UIObject : public fnd::ReferencedObject {
        Position position;
        Dimensions dimensions;
    public:
        virtual void* GetClassId();
        virtual void UnkFunc1() {}
        virtual void Update() {}
    };
}
