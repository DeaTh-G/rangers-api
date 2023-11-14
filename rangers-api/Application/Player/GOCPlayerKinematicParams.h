#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
        csl::math::Vector4& GetPosition();
        void SetPosition(const csl::math::Vector4& position);
        void SetVelocity(const csl::math::Vector4& velocity);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
