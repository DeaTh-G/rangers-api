#pragma once

namespace hh::ui {
    class UIObject : fnd::ReferencedObject {
        Position position;
        Dimensions dimensions;
    public:
        virtual void* GetClassId();
        virtual void UnkFunc1() {}
        virtual void Update() {}
    };
}
