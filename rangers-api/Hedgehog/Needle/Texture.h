#pragma once

#define NEEDLE_RESOURCE_TEXTURE 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    class Texture : public SurfaceBase {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXTURE;
    };
}
