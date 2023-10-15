#pragma once

namespace hh::ui {
    class alignas(8) UIElement : public fnd::ReferencedObject {
        csl::fnd::Delegate<void ()> unk1;
        csl::fnd::Delegate<void ()> unk2;
        csl::fnd::Delegate<void ()> unk3;
        fnd::Handle<game::GameObject> hGameObject;
        fnd::Handle<GOCUICollider> hGOCUICollider;
        fnd::Handle<GOCSprite> hGOCSprite;
        csl::fnd::Delegate<void ()> unk7;
        csl::fnd::Delegate<void ()> unk8;
        csl::ut::VariableString unk9;
        csl::ut::VariableString unk10;
        fnd::Handle<fnd::RefByHandleObject> hLayer;
        fnd::Handle<fnd::RefByHandleObject> hCast;
        void* unk12;
        csl::fnd::Delegate<void ()> unk13;
        bool maybeHasCast;
        bool unk14b;
        bool unk14c;
        bool unk14d;
    public:
        UIElement(csl::fnd::IAllocator* pAllocator);
        GOCSprite* GetGOCSprite();
        game::GameObject* GetGameObject();
        virtual void GetClassId();
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual bool UnkFunc9() { return false; }
        virtual void UnkFunc10() {}
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual bool CheckSomethingInTheCast();
        virtual bool UnkFunc14() { return true; }
        virtual void UnkFunc15() {}
        virtual void NotifyUnk1();
        virtual void NotifyUnk3();
        virtual void NotifyUnk2();
        virtual void DoSomethingWithUnk7();
    };
}