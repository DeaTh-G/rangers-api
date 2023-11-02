#pragma once

namespace hh::gfnd {
    struct ViewportDimensions {
        float x;
        float y;
        float width;
        float height;
    };


    struct alignas(16) ViewportData {
        csl::math::Matrix44 unkMatrix;
        csl::math::Matrix44 unkMatrix2;
        ViewportDimensions viewportDimensions;
        csl::math::Vector4 unk4;
        csl::math::Matrix44 projMatrix;
        uint32_t unk5;
        csl::math::Vector4 unk6;
        float fov;
        float aspectRatio;
        float nearClip;
        float farClip;
        uint64_t unk7;
        uint64_t unk8;

        ViewportData(csl::fnd::IAllocator* pAllocator);
    };

    class GraphicsContext : public fnd::BaseObject {
    public:
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::fnd::IAllocator* allocator1;
        void* unk4;
        hh::needle::ImplDX11::RenderingDeviceDX11* renderingDevice;
        ViewportData viewportData;
        uint64_t unk7;
        uint64_t unk8;
        int unk9;
        csl::fnd::Mutex mutex;
        int64_t unk10;
        int64_t unk11;
        GraphicsContext(csl::fnd::IAllocator* pAllocator);
        static GraphicsContext* instance;
    };
}
