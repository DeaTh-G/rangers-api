
#pragma once

namespace hh::fnd {
    class ResourceTypeRegistry : public BaseObject, public csl::fnd::Singleton<ResourceTypeRegistry> {
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByName;
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByExtension;

        static const ResourceTypeInfo* typeInfos[81];
        static csl::ut::Pair<const char*, const ResourceTypeInfo*> typeInfoExtensionMap[44];
    public:
        ResourceTypeRegistry();
        static ResourceTypeRegistry* Create();
        csl::ut::MoveArray<const ResourceTypeInfo*> GetTypeInfos();
        const char* GetExtensionByTypeInfo(const ResourceTypeInfo* typeInfo);
        const ResourceTypeInfo* GetTypeInfoByExtension(const char* extension);
    };
}
