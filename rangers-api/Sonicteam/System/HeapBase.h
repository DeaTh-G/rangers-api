#pragma once

namespace csl::fnd {
    struct HeapBlock {

    };

    class alignas(8) HeapBase {
        void* unk0;
        bool unk1;
        char name[10];
        uint64_t unk2;
        uint64_t unk3;
        csl::ut::LinkList<HeapBlock> blocks;
        uint64_t unk8;
        uint64_t unk9;
        bool unk10;
        uint32_t unk11;
        uint32_t unk12;
        bool unk13;
        uint64_t unk14;
        uint64_t unk15;
        uint32_t unk16;
    public:
        HeapBase(const char* name);
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
        virtual void Free(void* in_pMemory) = 0;
        void SetName(const char* name);
    };
}
