#pragma once

namespace hh::fnd {
    class ResourceManager : public fnd::BaseObject, public ResourceManagerRelatedUnk1Listener, public csl::fnd::Singleton<ResourceManager> {
        csl::ut::MoveArray<void*> unk1;
        ResourceLoader::Unk2 unk2;
        csl::ut::PointerMap<void*, void*> unk3;
        ResourceManagerRelatedUnk1 unk4;
        csl::ut::MoveArray<void*> unk5;
        csl::ut::MoveArray<void*> unk6;
        uint64_t unk7;
        uint64_t unk8;
        uint64_t unk9;
        csl::ut::MoveArray<void*> unk10;
        csl::fnd::Mutex mutex;

    public:
        ResourceManager();

        class ResourceListener {
        public:
            virtual ~ResourceListener();
            virtual void RL_UnkFunc1(ManagedResource* resource) {}
            virtual void RL_UnkFunc2(void* unkParam1) {}
        };
    };
}
