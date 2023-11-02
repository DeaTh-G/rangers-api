#pragma once

namespace hh::fnd {
    class ResourceManager;
    class DynamicResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        ResourceManager* resourceManager;
        void* unk2;
        csl::ut::InplaceMoveArray<void*, 1> unk3;
        csl::ut::StringMap<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        csl::fnd::Mutex mutex;
    public:
        DynamicResourceContainer(csl::fnd::IAllocator* allocator, const ResourceTypeInfo* typeInfo);
        void SetFilePathResolver(FilePathResolver* filePathResolver);
    };
}
