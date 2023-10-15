#pragma once

namespace app::ui {
    class UIMusicSelect : public hh::game::GameObject, public hh::ui::UIListener, public hh::hid::ActiveDeviceManagerListener, public app::snd::CustomSoundListener {
        hh::ui::LayerController* layerController;
        hh::ui::LayerController* refBtn;
        hh::ui::LayerController* refPcBtnT;
        hh::ui::LayerController* refPcBtnB;
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
        bool someMusicSelectFlags;
        bool field_2E2;
        bool field_2E3;
        bool field_2E4;
        float field_2E6;
        uint32_t field_2E8;
        uint32_t field_2EC;
        uint32_t field_2F4;
        uint32_t float2;
        bool field_2FC;
    public:
        UIMusicSelect* Instantiate(csl::fnd::IAllocator* pAllocator);

        virtual void Initialize();
        virtual void Dispose();
        virtual void Update(uint64_t unkParam, uint64_t unkParam2);
		virtual void UnkFunc11(uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4);
    };
}
