#pragma once

#define NEEDLE_RESOURCE_MATERIAL 0x303030303054414Dui64 // '00000TAM'

namespace hh::needle {
    class MaterialResource : public TNeedleRefcountUniqueObjectBase<TNeedleRefcountResource<NEEDLE_RESOURCE_MATERIAL, NeedleRefcountResource>> {

    };

    template<typename T>
    void BuildMaterialResourceFromResolvedMemoryImage(RenderingDevice* device, const void* image, MaterialResource** resource, bool unkParam);
}