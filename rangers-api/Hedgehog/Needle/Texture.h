#pragma once

#define TEXTURE_0                 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    class Texture : public SurfaceBase {
    public:
        static size_t constexpr InterfaceId = TEXTURE_0;
    };
}
