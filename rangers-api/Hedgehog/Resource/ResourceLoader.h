#pragma once

namespace hh::fnd {
    class ResourceLoader : public ReferencedObject, public FileInfoListener, public FileBindListener {
    public:
        struct Unk1 {
            uint32_t unk1{ 1 };
            const char* unk2{ "" };
        };

        class Unk2 : public BaseObject {
            class Unk1 : public ReferencedObject {
                csl::ut::MoveArray<void*> unk1;
                csl::ut::MoveArray<void*> unk2;
                csl::ut::PointerMap<void*, void*> unk3;
            public:
                Unk1(csl::fnd::IAllocator* allocator);
            };

            csl::ut::MoveArray<Unk1*> unk1s;
            csl::ut::PointerMap<const ResourceTypeInfo*, Unk1*> unk1sByTypeInfo;
            SimpleResourceContainer* simpleResourceContainer;
        public:
            Unk2(csl::fnd::IAllocator* allocator);
            void LoadTypeInfo(const ResourceTypeInfo* typeInfo);
            void SetSimpleResourceContainer(SimpleResourceContainer* simpleResourceContainer); 
        };

        struct Unk3 {
            uint64_t unk1;
            bool unk2;
            csl::ut::VariableString unk3;

            Unk3(csl::fnd::IAllocator* allocator);
        };

        Unk2 unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        Unk3 unk5;
        csl::fnd::IAllocator* otherAllocator;
        csl::ut::VariableString unk6;
        csl::ut::MoveArray<void*> unk7;
        uint16_t unk8;

        ResourceLoader(csl::fnd::IAllocator* allocator);
        inline static ResourceLoader* Instantiate(csl::fnd::IAllocator* allocator) {
            return new (allocator) ResourceLoader(allocator);
        }

        void LoadPackfile(const char* uri, uint32_t unk);
        void LoadResource(const Uri& uri, ResourceTypeInfo resourceTypeInfo, int unk, uint32_t unk2, Unk1& unk3);
    };
}
