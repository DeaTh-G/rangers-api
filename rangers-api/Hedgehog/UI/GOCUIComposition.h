#pragma once

namespace hh::ui {
    class UIElement;
    class UIElementGroup;
    class UIElementGroupContainer;
    class GOCUIComposition : public game::GOComponent {
        csl::ut::MoveArray<void*> unk101;
        csl::fnd::Delegate<void (GOCUIComposition* gocUIComposition)> onCurrentGroupChange;
        bool unk103;
        int currentGroupIndex;
        UIElementGroupContainer* rootContainer;
        csl::ut::MoveArray<UIElementGroup*> elementGroups;
        csl::ut::MoveArray<void*> unk107;
        csl::ut::MoveArray<void*> unk108;
        SurfRide::Project* project;
        uint64_t unk110;
        uint32_t unk111;
        UITextInterface* textInterface;
        csl::ut::MoveArray<void*> unk113;
        uint64_t unk114;

        static GOCUIComposition* Instantiate(csl::fnd::IAllocator* pAllocator);
        void Unk12421(SurfRide::Project* project, csl::ut::InplaceMoveArray<const char*, 32>& sceneNames);
        int FindGlobalIndexOfGroup(UIElementGroupContainer* container, const char* name);
        void SetCurrentGroupByGlobalIndex(int index);
    public:
        struct alignas(8) Config {
            uint32_t unk1;
            uint64_t unk2;
            uint32_t unk3;
        };

        static game::GOComponentClass* GetClass();
        void Initialize(const Config& config);
        void SetProject(SurfRide::Project* project);
        void SetCurrentGroup(const char* name);
        void DoSomething();
        UIElement* FindElement(const char* name);
    };
}
