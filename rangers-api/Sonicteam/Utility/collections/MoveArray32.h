#pragma once

namespace csl::ut {
    template<typename T>
    class MoveArray32 {
        T* buffer;
        uint32_t length;
        uint32_t capacity;
        csl::fnd::IAllocator* allocator;
    };
}
