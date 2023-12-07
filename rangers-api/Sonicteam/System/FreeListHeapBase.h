#pragma once

namespace csl::fnd {
    class FreeListHeapBase : public HeapBase {
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint64_t unk107;
        uint64_t unk108;
        uint32_t unk109;
        uint32_t unk110;
        bool initialized;
    public:
        FreeListHeapBase(const char* name);
        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };
}
