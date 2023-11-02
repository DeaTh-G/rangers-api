#pragma once

// Texture implementation id
#define DX11_TEXTURE_V0           0x3056585431315844ui64 // '0VXT11XD'

// Texture buffer types
#define DX11_SBUFFER_TEXTURE_2D   0x3254465542313144ui64 // '2TFUB11D'

// Texture view types
#define DX11_VIEW_TEXTURE_2D      0x3258545756313144ui64 // '2XTWV11D'

namespace hh::needle::ImplDX11 {
    class SBufferTexture2D {
    public:
        static constexpr size_t InterfaceId = DX11_SBUFFER_TEXTURE_2D;
        ID3D11Texture2D* buffer;
    };

    class SViewTexture2D {
    public:
        static constexpr size_t InterfaceId = DX11_VIEW_TEXTURE_2D;
        ID3D11ShaderResourceView* view;
    };

    template<typename TextureBuffer, typename TextureView, size_t MyInterfaceId = DX11_TEXTURE_V0>
    class TextureDX11Impl {
        TextureBuffer buffer;
        TextureView view;

    public:
        static constexpr size_t InterfaceId = MyInterfaceId;

        virtual ~TextureDX11Impl();
        void* QueryInterface(size_t magic) {
            switch (magic) {
                case MyInterfaceId: return this;
                case TextureBuffer::InterfaceId: return &buffer;
                case TextureView::InterfaceId: return &view;
                default: return nullptr;
            }
        }
    };
}
