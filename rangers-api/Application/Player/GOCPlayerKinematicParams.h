#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
		virtual void* GetClassId() override;
		virtual void Update() override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        csl::math::Vector4& GetPosition();
        void SetPosition(const csl::math::Vector4& position);
        void SetVelocity(const csl::math::Vector4& velocity);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
