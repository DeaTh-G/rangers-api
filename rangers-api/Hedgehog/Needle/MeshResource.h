#pragma once

#define NEEDLE_RESOURCE_MESH_RESOURCE 0x305345524853454Dui64 // '0SERHSEM'

namespace hh::needle {
    class MeshResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_MESH_RESOURCE, NeedleRefcountResource> {
        void GetAABB(float_vector3 (*aabb)[2]);
    };
}
