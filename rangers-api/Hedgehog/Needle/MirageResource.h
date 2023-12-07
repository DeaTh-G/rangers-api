#pragma once

namespace hh::needle {
    class RenderingDevice;

    namespace mirageresourceimage {
        bool ResolvePointer(void* ptr);
        bool UnResolvePointer(void* ptr);
    }

    bool ResolveMirageResourceBinary(void* binaryData);
    bool UnResolveMirageResourceBinary(void* binaryData);
    
    void LoadMirageMaterial2(RenderingDevice* device);
}
