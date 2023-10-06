#pragma once

namespace app::ui {
    class UIMusicSelect : public hh::game::GameObject, public hh::ui::UIListener, public hh::hid::ActiveDeviceManagerListener, public app::snd::CustomSoundListener {
        hh::ui::LayerController* layerController;
        void* refBtn;
        void* refPcBtnT;
        void* refPcBtnB;
        float float1;
        bool field_284;
        hh::game::GOCInput* gocInput;
        csl::ut::MoveArray<void*> songs;
        csl::ut::MoveArray<void*> field_2B0;
        uint32_t playingSong;
        uint32_t playingSongIdx;
        uint32_t songCount;
        bool field_2DC;
        bool inlooporloop;
        bool field_2E0;
        bool field_2E1;
        bool field_2E2;
        uint32_t field_2E4;
        uint32_t field_2E8;
        uint32_t field_2EC;
        uint32_t field_2F4;
        uint32_t float2;
        bool field_2FC;
    public:
        UIMusicSelect* Instantiate(csl::fnd::IAllocator* pAllocator);
        void Load(bool unk);
    };
}
