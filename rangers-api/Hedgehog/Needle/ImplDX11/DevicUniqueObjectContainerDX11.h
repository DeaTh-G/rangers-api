#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class DevicUniqueObjectContainerDX11 {
        public:
            void* unk[2];
            ID3D11Device* d3dDevice;
        };
    }
}