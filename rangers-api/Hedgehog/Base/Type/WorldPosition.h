#pragma once

namespace hh::fnd {
    struct WorldPosition {
        csl::math::Vector4 m_Position;
        csl::math::Quaternion m_Rotation;

        WorldPosition();
        void SetRotation(csl::math::Quaternion rotation) {
            m_Rotation = rotation;
        }
    };
}
