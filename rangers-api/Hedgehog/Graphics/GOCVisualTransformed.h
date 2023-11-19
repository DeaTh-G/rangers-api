#pragma once

namespace hh::gfx {
    class GOCVisualTransformed : public GOCVisual, public fnd::HFrame::Listener {
        uint64_t unk201;
        fnd::HFrame* frame;
        csl::math::Transform transform;
        csl::math::Matrix34 transformationMatrix; // ??
        uint8_t unk203;
        uint8_t unk203a;
        uint8_t unk203b;
        uint64_t unk204;
        uint8_t unk205;
        uint8_t unk205b;
        uint16_t handle2; // copied from messenger handle in ctor
        uint16_t unk206b;
        csl::geom::Aabb* pTransformedAabb;
        csl::geom::Aabb aabb;
        csl::geom::Aabb transformedAabb;
    public:
        GOCVisualTransformed(csl::fnd::IAllocator* allocator);
		virtual void* GetClassId() override;
		virtual void Update() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual uint64_t UnkFunc1() override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;
        void UpdateTransform();
    };
}
