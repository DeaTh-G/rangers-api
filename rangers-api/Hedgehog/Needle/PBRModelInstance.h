#pragma once

namespace hh::needle {
    class PBRModelInstance : public ModelInstance {
        void SetShadowReceiveFlag(bool enabled);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
    };
}
