#pragma once

namespace hh::fnd {
    template<typename T>
    struct alignas(8) RflArray {
        const T* items;
        const uint32_t count;
    };
}
