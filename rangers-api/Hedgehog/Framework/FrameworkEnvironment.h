#pragma once

namespace hh::fw {
    class FrameworkEnvironment {
    public:
        class CriSystemThing {
        public:
            csl::ut::InplaceMoveArray<void*, 10> unk1;
            csl::ut::InplaceMoveArray<void*, 30> unk2;
            csl::ut::InplaceMoveArray<void*, 10> unk3;
            CriSystemThing();
        };

        bool unk1;
        uint64_t unk2;
        uint16_t unk3;
        uint32_t unk4;
        Window* window;
        uint64_t unk6;
        uint64_t unk7;
        int64_t unk8;
        uint64_t unk9;
        uint64_t unk10;
        uint64_t unk11;
        EventStack* eventStack;
        CriSystemThing criSystemThing;
        fnd::Reference<font::FontContainer> fontContainer;
        uint8_t flags;

        FrameworkEnvironment(csl::fnd::IAllocator* allocator);
    };
}
