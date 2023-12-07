#pragma once

namespace hh::gfx {
    enum class TextureWrapMode : uint8_t
    {
        REPEAT = 0,
        MIRROR = 1,
        CLAMP = 2,
        MIRROR_ONCE = 3,
        BORDER = 4
    };

    struct TextureData {
        uint32_t texName;
        uint8_t texCoordIndex;
        TextureWrapMode wrapModeU;
        TextureWrapMode wrapModeV;
        uint8_t padding;
        uint32_t type;
    };

    template<typename T>
    struct MaterialParamData
    {
        struct Vec4 {
            T x;
            T y;
            T z;
            T w;
        };
        uint8_t flag1;
        uint8_t flag2;
        uint8_t valueCount;
        uint8_t flag3;
        uint32_t name;
        uint32_t values;
    };

    struct MaterialData {
        uint32_t shaderName;
        uint32_t subShaderName;
        uint32_t textureEntryNames;
        uint32_t textureEntries;
        uint8_t alphaThreshold;
        uint8_t noBackfaceCulling;
        uint8_t useAdditiveBlending;
        uint8_t unknownFlag1;
        uint8_t float4ParamCount;
        uint8_t int4ParamCount;
        uint8_t bool4ParamCount;
        uint8_t textureEntryCount;
        uint32_t float4Params;
        uint32_t int4Params;
        uint32_t bool4Params;
    };

    class ResMaterial : public fnd::ManagedResource {


    public:
        MANAGED_RESOURCE_CLASS_DECLARATION(ResMaterial)
    };
}
