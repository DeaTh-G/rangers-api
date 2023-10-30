#pragma once

namespace csl::ut {
    template<typename T>
    struct alignas(4) Color {
        T r;
        T g;
        T b;
        T a;
    };
}
