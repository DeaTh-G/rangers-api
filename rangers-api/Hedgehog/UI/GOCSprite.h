#pragma once

namespace hh::ui {
    class GOCSprite : public game::GOComponent {
        hh::fnd::LogData log1;
        hh::fnd::LogData log2;
        hh::fnd::LogData log3;
        uint64_t field_E0;
        uint64_t field_E8;
        hh::ui::ResSurfRideProject* projectResource;
        csl::ut::VariableString projectName;
        bool field_108;
        uint64_t field_110;
        csl::ut::MoveArray<void*> field_118;
        csl::ut::MoveArray<void*> field_138;
        csl::ut::MoveArray<void*> field_158;
        uint64_t renderable;
        bool field_180;
        uint16_t field_182;
        uint32_t field_184;
        uint32_t field_188;
        uint64_t field_190;
        uint64_t field_198;
        uint64_t field_1A0;
        uint64_t field_1A8;
        csl::ut::MoveArray<void*> casts;
        csl::ut::StringMap<void*> castMap;
        csl::ut::MoveArray<void*> layers;
        csl::ut::StringMap<void*> layerMap;
        
        static GOCSprite* Instantiate(csl::fnd::IAllocator* pAllocator);
    public:
        struct alignas(8) Config {
            hh::ui::ResSurfRideProject* projectResource;
            const char* name;
            uint32_t unk1;
            bool unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
        };

        void Initialize(const Config& config);
    };
}