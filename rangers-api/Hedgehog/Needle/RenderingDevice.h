#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE 0x56454452444e4552ui64

namespace hh::needle {
    struct TextureCreationInfo {
    };
    
    struct TextureViewCreationInfo {
    };

    class RenderingDevice : public TNeedleRefcountResource<NEEDLE_RESOURCE_RENDERING_DEVICE, NeedleRefcountResource> {
    public:
        virtual void CreateDeviceContext() = 0;
        virtual void* UnkFunc9() = 0;
        virtual void OtherCreateDeviceContext() = 0; // CreateDeviceDispatch?
        virtual Texture* CreateTexture(const TextureCreationInfo& creationInfo) = 0;
        virtual void CreateTextureView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual void UnkFunc12() = 0;
        virtual void UnkFunc13() = 0;
        virtual void UnkFunc14() = 0;
        virtual void UnkFunc15() = 0;
        virtual void UnkFunc16() = 0;
        virtual void UnkFunc17() = 0;
        virtual void UnkFunc18() = 0;
        virtual void UnkFunc19() = 0;
        virtual void UnkFunc20() = 0;
        virtual void UnkFunc21() = 0;
        virtual void UnkFunc22() = 0;
        virtual void UnkFunc23() = 0;
        virtual void UnkFunc24() = 0;
        virtual void UnkFunc25() = 0;
        virtual void UnkFunc26() = 0;
        virtual void UnkFunc27() = 0;
        virtual void UnkFunc28() = 0;
        virtual void UnkFunc29() = 0;
        virtual void UnkFunc30() = 0;
        virtual void UnkFunc31() = 0;
        virtual void UnkFunc32() = 0;
        virtual void UnkFunc33() = 0;
        virtual void UnkFunc34() = 0;
        virtual void UnkFunc35() = 0;
        virtual void UnkFunc36() = 0;
        virtual void UnkFunc37() = 0;
        virtual void UnkFunc38() = 0;
        virtual void UnkFunc39() = 0;
        virtual void UnkFunc40() = 0;
        virtual void UnkFunc41() = 0;
        virtual void UnkFunc42() = 0;
        virtual void UnkFunc43() = 0;
        virtual void UnkFunc44() = 0;
        virtual void UnkFunc45() = 0;
        virtual void UnkFunc46() = 0;
    };
}