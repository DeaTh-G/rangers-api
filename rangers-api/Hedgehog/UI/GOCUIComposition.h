#pragma once

namespace hh::ui {
    class UIElementGroupContainer;
    class GOCUIComposition : public game::GOComponent {
        csl::ut::MoveArray<void*> unk101;
        csl::ut::MoveArray<void*> unk102;
        bool unk103;
        uint32_t unk104;
        UIElementGroupContainer* container;
        csl::ut::MoveArray<void*> unk106;
        csl::ut::MoveArray<void*> unk107;
        csl::ut::MoveArray<void*> unk108;
        SurfRide::Project* project;
        uint64_t unk110;
        uint32_t unk111;
        uint64_t unk112;
        csl::ut::MoveArray<void*> unk113;
        uint64_t unk114;

        static GOCUIComposition* Instantiate(csl::fnd::IAllocator* pAllocator);
    public:
        struct alignas(8) Config {
            uint32_t unk1;
            uint64_t unk2;
            uint32_t unk3;
        };

        static game::GOComponentClass* GetClass();
        void Initialize(const Config& config);
        void SetProject(SurfRide::Project* project);
        void DoSomething();
        UIElement* GetUIElement(const char* name);
    };
}
