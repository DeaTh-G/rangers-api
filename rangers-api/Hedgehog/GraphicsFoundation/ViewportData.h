#pragma once

namespace hh::gfnd {
    struct ViewportDimensions {
        float x;
        float y;
        float width;
        float height;
        float maybeRenderWidth;
        float maybeRenderHeight;
    };

    struct alignas(16) ViewportData {
        csl::math::Matrix44 viewMatrix;
        csl::math::Matrix44 inverseViewMatrix;
        ViewportDimensions viewportDimensions;
        csl::math::Matrix44 projMatrix;
        uint32_t unk5;
        csl::math::Vector4 unk6;
        float fov;
        float aspectRatio;
        float nearClip;
        float farClip;
        uint64_t unk7;
        uint64_t unk8;

        ViewportData();
        ViewportData& operator=(const ViewportData& other);
        void SetDimensions(const ViewportDimensions& other);
    };
}
