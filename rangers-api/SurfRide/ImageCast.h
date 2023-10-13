#pragma once

namespace SurfRide {
    struct SRS_IMAGECAST {
        uint32_t Flags;
        csl::math::Vector2 Size;
        csl::math::Vector2 PivotPoint;
        csl::ut::Color<uint8_t> VertexColorTopLeft;
        csl::ut::Color<uint8_t> VertexColorBottomLeft;
        csl::ut::Color<uint8_t> VertexColorTopRight;
        csl::ut::Color<uint8_t> VertexColorBottomRight;
        short CropIndex0;
        short CropIndex1;
        short CropRef0Count;
        short CropRef1Count;
        size_t CropRef0Offset;
        size_t CropRef1Offset;
        size_t FontInfoOffset;
        size_t field_38;
        size_t EffectOffset;
    };

    class FontInfo;
    class ImageCast : public Cast {
        const SRS_IMAGECAST* imageCastData;
        uint32_t Flags;
        FontInfo* fontInfo;
        uint32_t Size;
        uint32_t unk105;
        csl::ut::Color<uint8_t> vertexColors[4];
        short cropIndex0;
        short cropIndex1;
        short unk104;
        // TODO: more fields in here
    public:
        ImageCast(const SRS_CASTNODE& castData, void* unkParam, Layer* layer);
    };
}
