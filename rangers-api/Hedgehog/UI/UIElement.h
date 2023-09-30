#pragma once

namespace hh::ui {
    class alignas(8) UIElement : public fnd::ReferencedObject {
        hh::fnd::LogData unk1;
        hh::fnd::LogData unk2;
        hh::fnd::LogData unk3;
        fnd::Handle<game::GameObject> hGameObject;
        fnd::Handle<ui::GOCUICollider> hGOCUICollider;
        fnd::Handle<ui::GOCSprite> hGOCSprite;
        csl::fnd::Delegate<void ()> unk7;
        csl::fnd::Delegate<void ()> unk8;
        csl::ut::VariableString unk9;
        csl::ut::VariableString unk10;
        void* unk11;
        void* unk12;
        csl::fnd::Delegate<void ()> unk13;
        uint32_t unk14;
    };
}