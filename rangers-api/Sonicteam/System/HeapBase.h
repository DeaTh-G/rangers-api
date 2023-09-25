#pragma once

namespace csl::fnd {
    class alignas(8) HeapBase {
        void* unk0;
        bool unk1;
        const char name[10];
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint32_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        uint64_t unk8;
        uint64_t unk9;
        char unk10;
        uint64_t unk11;
        char unk12;
        uint64_t unk13;
        uint64_t unk14;
        uint32_t unk15;
    public:
		virtual ~HeapBase() = default;
		virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
		virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
		virtual void Free(void* in_pMemory) = 0;
    };
}
