#pragma once

namespace hh::ui {
    class UIListViewElement;

    class UIListViewItemBase : public UIObject {
        UIListViewElement* listView;
        uint64_t unk102;
        uint64_t unk103;
        int32_t index;
        uint16_t unk105;
        bool unk106;
    public:
        UIListViewItemBase(csl::fnd::IAllocator* pAllocator);
        void SetListViewElement(hh::ui::UIListViewElement* listViewElement);
        void SetDimensions(const Dimensions& dimensions);
        virtual void* GetClassId();
        virtual void Update();
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
    };

    class UIListViewItem : public UIListViewItemBase {
        struct alignas(8) Unk2 {
            uint32_t unk1;
            csl::ut::VariableString unk2;
            csl::ut::VariableString unk3;
            csl::ut::VariableString unk4;
            csl::ut::VariableString unk5;
            uint32_t unk6;
            uint64_t unk7;
            uint32_t unk8;
        public:
            void Clear();
        };

        struct alignas(8) Unk1 {
            csl::fnd::IAllocator* pAllocator;
            Unk2 unk1;
            csl::ut::MoveArray<void*> unk2;
        public:
            Unk1(csl::fnd::IAllocator* pAllocator);
            void Set(const char* str1, const char* str2);
        };

        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        Unk1 unk3;
    public:
        UIListViewItem(csl::fnd::IAllocator* pAllocator, uint64_t unk);
        void Set(const char* str1, const char* str2);
        virtual void* GetClassId();
        virtual void UnkFunc3();
        virtual void UnkFunc4();
    };

    struct ListViewEventArg {
    };

    class UIListViewElement : public UIElement {
        class alignas(8) ScrollController : public fnd::ReferencedObject {
            uint32_t unk1;
            uint32_t unk1b;
            uint64_t unk2;
            UIListViewElement* pListView;
            UIPanel* panel;
            uint16_t unk4;
            int16_t scrollPosition;
            uint16_t unk5;
            int16_t panelHeight;
            uint32_t unk6;
            bool enabled;
            uint32_t unk8;
            uint32_t unk9;
            int unk10;
        public:
            void ScrollTo(uint32_t scrollPosition);
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
                int scrollBarMinSize;  // User data SCROLL_BAR_MIN_SIZE, max 100
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
            fnd::Handle<SurfRideCastHandle> unk42;
            UIPanel* panel;
            ScrollController* pScrollController;
            uint64_t unk44;
            uint64_t unk45;
        };

        csl::fnd::Delegate<void ()> unk15;
        csl::fnd::Delegate<void (UIListViewElement*, ListViewEventArg&)> unk16;
        csl::fnd::Delegate<void ()> unk17;
        csl::fnd::Delegate<void ()> unk18;
        csl::fnd::Delegate<void ()> unk19;
        csl::fnd::Delegate<void (UIListViewElement*, bool)> onScroll;
        csl::ut::MoveArray<void*> unk21;
        csl::ut::MoveArray<void*> unk22;
        bool unk23;
        float unk24;
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
        bool unk33;
        bool scrollEnabled;
        bool fixedLayout;
        bool unk34;
        bool unk35;
        bool unk36;
        bool unk37;
        bool unk38;
        bool unk39;
    public:

        UIListViewElement(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);
        void AddItem(UIListViewItem* item);
        void Reset();
        UIListViewItem* GetItem(uint32_t index);
        LayerController* GetItemLayerController(UIListViewItem* item);
        LayerController* GetSomeLayerController();
        void NUnkFunc1(int a2, char a3, char a4);
        virtual void GetClassId();
        virtual void UnkFunc2();
        virtual void UnkFunc3();
        virtual void UnkFunc4();
        virtual void UnkFunc5();
        virtual bool UnkFunc9();
        virtual void UnkFunc10();
        virtual void UnkFunc11();
        virtual bool CheckSomethingInTheCast() { return true; }
        virtual bool UnkFunc14();
        virtual void NotifyUnk1();
        virtual void NotifyUnk3();
    };
}
