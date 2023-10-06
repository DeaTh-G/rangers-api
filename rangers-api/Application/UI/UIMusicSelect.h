#pragma once

namespace app::ui {
    class UIMusicSelect : public hh::game::GameObject, public hh::ui::UIListener, public hh::hid::ActiveDeviceManagerListener, public app::snd::CustomSoundListener {
        hh::ui::LayerController* layerController;
        // refBtn          dq ?
        // refPcBtnT       dq ?
        // refPcBtnB       dq ?
        // float1          dd ?
        // field_284       db ?
        //                 db ? ; undefined
        //                 db ? ; undefined
        //                 db ? ; undefined
        // field_288       dq ?
        // songs           csl::ut::MoveArray<void*> ?
        // field_2B0       csl::ut::List ?
        // playingSong?    dd ?
        // playingSongIdx  dd ?
        // songCount       dd ?
        // field_2DC       db ?
        // inlooporloop    db ?
        //                 db ? ; undefined
        //                 db ? ; undefined
        // field_2E0       db ?
        // field_2E1       db ?
        // field_2E2       db ?
        //                 db ? ; undefined
        // field_2E4       dd ?
        // field_2E8       dd ?
        // field_2EC       dd ?
        //                 db ? ; undefined
        //                 db ? ; undefined
        //                 db ? ; undefined
        //                 db ? ; undefined
        // field_2F4       dd ?
        // float2          dd ?
        // field_2FC       db ?
    };
}