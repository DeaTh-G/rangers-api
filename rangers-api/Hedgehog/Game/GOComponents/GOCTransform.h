#pragma once

namespace hh::game {
    class GOCTransform : public GOComponent {
        uint64_t unk1;
        uint64_t unk2;
        GOCTransform* parent;
        uint32_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
    public:
        csl::math::Transform transform;
        fnd::HFrame* frame;
        char unk9;
        char unk10;
        char gocTransformFlags;
        uint32_t unk12;

        enum class Flag : unsigned char {
            TRANSFORM_POSITION = 1,
            TRANSFORM_ROTATION = 2,
        };

        struct alignas(8) Config {
        };

        GOCTransform(csl::fnd::IAllocator* pAllocator);

        void Initialize(const Config& config);
        void SetInheritedFlags(Flag flags);
        void SetLocalTransform(const csl::math::Transform& transform);
        void SetLocalTranslation(const csl::math::Vector3& position);
        void SetLocalRotation(const csl::math::Quaternion& rotation);
        void SetLocalTranslationAndRotation(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
        void SetParent(GOCTransform* parent);
        bool IsExistParent();
        
        inline GOCTransform* GetParent() {
            return parent;
        }
        
        GOCOMPONENT_CLASS_DECLARATION(GOCTransform)
    };
}
