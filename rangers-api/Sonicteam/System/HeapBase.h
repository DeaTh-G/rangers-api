#pragma once

namespace csl::fnd {
    class alignas(8) HeapBase {
        UNKNOWN(void*);
        UNKNOWN(bool);
        const char name[10];
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint32_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(char);
        UNKNOWN(uint64_t);
        UNKNOWN(char);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint32_t);
    public:
		virtual ~HeapBase() = default;
		virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
		virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
		virtual void Free(void* in_pMemory) = 0;
    };
}
