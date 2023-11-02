#pragma once

namespace hh::fnd {
    class SimpleResourceContainer : public ReferencedObject {
        class Unk1 : public ReferencedObject {
            const ResourceTypeInfo* typeInfo;
            csl::fnd::Mutex mutex;
        };
        csl::ut::MoveArray<Unk1*> unk1s;
        csl::ut::PointerMap<ResourceTypeInfo*, Unk1*> unk1sByTypeInfo;
    public:
        SimpleResourceContainer(csl::fnd::IAllocator* allocator);
        void LoadFromTypeInfos();
    };
}
