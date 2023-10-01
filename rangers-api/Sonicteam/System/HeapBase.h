#pragma once

namespace csl::fnd {
    class alignas(8) HeapBase {
        void* unk0;
        bool unk1;
        char name[10];
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint32_t unk5;
        void* unk6;
        void* unk7;
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
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
        virtual void Free(void* in_pMemory) = 0;
    };
}
