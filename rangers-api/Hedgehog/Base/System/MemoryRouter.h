#pragma once

namespace hh::fnd {
    class MemoryRouterAllocator : public csl::fnd::IAllocator {
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;
        uint64_t unk1;
    };

    class MemoryRouter;

    // csl::fnd::IAllocator* tempAllocator;

    // Temp allocator size is 0x40000 and works on stack.
    void InitializeTempAllocator(MemoryRouter* router, size_t size);
    csl::fnd::IAllocator* GetTempAllocator();

    class MemoryRouter {
        csl::fnd::IAllocator* allocators[2]; // 0: module allocator, 1: debug allocator
        static MemoryRouter* instance;
    public:
        static MemoryRouter* GetInstance();
        static void SetInstance(MemoryRouter* router);
        inline csl::fnd::IAllocator* GetTemp() { return fnd::GetTempAllocator(); }
        inline csl::fnd::IAllocator* GetModule() { return allocators[0]; }
        inline csl::fnd::IAllocator* GetDebug() { return allocators[1]; }
        static csl::fnd::IAllocator* GetTempAllocator();
        inline static csl::fnd::IAllocator* GetModuleAllocator() { return GetInstance()->GetModule(); }
        inline static csl::fnd::IAllocator* GetDebugAllocator() { return GetInstance()->GetDebug(); }
    };
}
