#pragma once

namespace hh::fnd {
    class ResourceManager : public fnd::BaseObject, public ResourceManagerRelatedUnk1Listener, public csl::fnd::Singleton<ResourceManager> {
        csl::ut::MoveArray<DynamicResourceContainer*> resourceContainers;
        ResourceLoader::Unk2 unk2;
        csl::ut::PointerMap<const ResourceTypeInfo*, uint32_t> resourceContainerIndexByTypeInfo;
        ResourceManagerRelatedUnk1 unk4;
        csl::ut::MoveArray<void*> unk5;
        csl::ut::MoveArray<void*> unk6;
        uint64_t unk7;
        uint64_t unk8;
        SimpleResourceContainer* simpleContainer;
        csl::ut::MoveArray<void*> unk10;
        csl::fnd::Mutex mutex;

        ManagedResource* GetResource(const char* name, const hh::fnd::ResourceTypeInfo* resourceTypeInfo);
    public:
        ResourceManager();
        void Setup();

        template<typename T>
        inline T* GetResource(const char* name) {
            return static_cast<T*>(GetResource(name, T::GetClass()));
        }

        class ResourceListener {
        public:
            virtual ~ResourceListener();
            virtual void RL_UnkFunc1(ManagedResource* resource) {}
            virtual void RL_UnkFunc2(void* unkParam1) {}
        };
    };
}
