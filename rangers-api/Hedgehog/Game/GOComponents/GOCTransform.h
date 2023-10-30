#pragma once

namespace hh::game {
    class GOCTransform : public GOComponent {
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
    public:
        csl::math::Vector4 position;
        csl::math::Vector4 rotation;
        csl::math::Vector4 scale;
        fnd::HFrame* hframe;
        uint64_t unk9;

        struct alignas(8) Config {
        };

        GOCTransform(csl::fnd::IAllocator* pAllocator);
        static GOCTransform* Instantiate(csl::fnd::IAllocator* pAllocator);

        void Initialize(const Config& config);
        
        GOCOMPONENT_CLASS_DECLARATION
    };
}
