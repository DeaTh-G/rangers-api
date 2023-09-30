#pragma once

namespace hh::ui {
    class UIListViewElement : public UIElement {
        class alignas(8) ScrollController : public fnd::ReferencedObject {
            uint64_t unk1;
            uint64_t unk2;
            UIListViewElement* pListView;
            UIPanel* panel;
            uint32_t unk4;
            uint16_t unk5;
            uint16_t documentHeight;
            uint32_t unk6;
            char unk7;
            uint64_t unk8;
            uint32_t unk9;
        };
        
        class ScissorCastListener : public fnd::ReferencedObject, public SurfRide::CastListener {
            UIListViewElement* listView;

            /*
             * Loaded from user data:
             *
             *   SCISSOR:
             *     SCISSOR_OFFSET_L
             *     SCISSOR_OFFSET_T
             *     SCISSOR_OFFSET_R
             *     SCISSOR_OFFSET_B
             */
            ScissorOffsets offsets;
        };

        struct UIListViewLayout {
            struct Dimensions {
                uint32_t rows;              // User data ROWS
                uint32_t cols;              // User data COLS
                uint32_t width;             // User data WIDTH
                uint32_t height;            // User data HEIGHT
                uint32_t currentWidth;
                uint32_t currentHeight;
                uint32_t currentRows;
                uint32_t currentCols;
            };

            struct alignas(8) Options {
                bool sizeFixed;
                float scrollTime;           // User data SCROLL_TIME
                float grabAdjustScrollTime; // User data GRAB_ADJUST_SCROLL_TIME
                Dimensions dimensions;
                uint32_t scrollStartRow;
                uint32_t scrollBarMinSize;  // User data SCROLL_BAR_MIN_SIZE, max 100
                uint32_t scrollLargeChange; // User data SCROLL_LARGE_CHANGE
                bool scrollEnabled;         // User data SCROLL_ENABLED
                bool loopHorizontally;      // User data LOOP || LOOP_H
                bool loopVertically;        // User data LOOP || LOOP_V
                bool fixedLayout;           // User data FIXED_LAYOUT
                bool scrollStartFixed;      // User data SCROLL_START_FIXED
                bool waitItemActIn;         // User data WAIT_ITEM_ACT_IN
            };

            Options options;
            uint32_t documentWidth;
            uint32_t documentHeight;
            uint32_t unk42;
            UIPanel* panel;
            ScrollController* pScrollController;
            uint64_t unk44;
            uint64_t unk45;
        };

        UIListViewElement();
        csl::fnd::Delegate<void ()> unk15;
        csl::fnd::Delegate<void ()> unk16;
        csl::fnd::Delegate<void ()> unk17;
        csl::fnd::Delegate<void ()> unk18;
        csl::fnd::Delegate<void ()> unk19;
        csl::fnd::Delegate<void ()> unk20;
        csl::ut::MoveArray<void*> unk21;
        csl::ut::MoveArray<void*> unk22;
        char unk23;
        uint32_t unk24;
        UIListViewLayout layout;
        csl::ut::MoveArray<void*> unk26;
        csl::ut::MoveArray<void*> unk27;
        csl::ut::MoveArray<void*> unk28;
        csl::math::Vector4 unk29;
        csl::math::Vector4 unk30;
        uint32_t scrollLargeChange;
        uint32_t unk31;
        float grabAdjustScrollTime;
        uint32_t unk32;
        uint32_t unk33;
        uint32_t unk34;
        bool unk35;
    };
}
