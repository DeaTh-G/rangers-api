#pragma once

namespace hh::ui {
    class GOCSprite : public game::GOComponent {
        hh::fnd::LogData log1;
        hh::fnd::LogData log2;
        hh::fnd::LogData log3;
        uint64_t field_E0;
        uint64_t field_E8;
        uint64_t field_F0;
        csl::ut::VariableString field_F8;
        uint64_t field_108;
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
        csl::ut::MoveArray<void*> field_1B0;
        csl::ut::StringMap<void*> field_1D0;
        csl::ut::MoveArray<void*> field_1F0;
        csl::ut::StringMap<void*> field_210;
    public:
        static GOCSprite* Instantiate(csl::fnd::IAllocator* pAllocator);
    };
}