#pragma once

namespace hh::fw::heap {
    struct SystemMemoryParam {
        size_t unk1;
        size_t systemHeapSize;
        size_t unk3;
        size_t unk4;
        size_t mainHeapSize;
        size_t criSystemHeapSize;
    };

    struct MemoryParam {
    };

    struct HeapDefinition {
        uint32_t id;
        const char* name;
        uint64_t unk2;
        uint64_t heapSize;
    };

    class LocalHeap : public csl::fnd::FreeListHeapBase {
        csl::fnd::Mutex mutex;
        csl::ut::InplaceMoveArray<csl::ut::Pair<unsigned int, HeapBase*>, 8> heaps;
        fnd::MemoryRouter* memoryRouter;
        const SystemMemoryParam* systemMemoryParam;
        const MemoryParam* memoryParam;
        size_t unkParam;
        static HeapDefinition heapDefs[3];
    public:
        LocalHeap(void* unkParam1, size_t unkParam2);
        void setup(const SystemMemoryParam* systemMemoryParam, const MemoryParam* memoryParam, size_t unkParam);
        void* GetBottomBlock();
        static LocalHeap* instance;
    };

    fnd::MemoryRouter* localInitUtilRsdx(const SystemMemoryParam* systemMemoryParam, const MemoryParam* memoryParam, size_t unkParam);
}
