#pragma once

#define NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT  0x304F535631315844ui64 // '0OSV11XD'
#define NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT   0x304F535031315844ui64 // '0OSP11XD'
#define NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT 0x304f534331315844ui64 // '0OSC11XD'

namespace hh::needle::ImplDX11 {
    class SShaderContext2 {
    };

    typedef NeedleResourceContainer<VertexShader, SShaderContext2, NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> VertexShader;
    typedef NeedleResourceContainer<PixelShader, SShaderContext2, NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> PixelShader;
    typedef NeedleResourceContainer<ComputeShader, SShaderContext2, NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> ComputeShader;
}
