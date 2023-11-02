#pragma once

namespace csl::ut {
    // No, this alignas is not a bug, this is actually how the game works!
    template<typename T>
    struct alignas(4) Color {
        T r;
        T g;
        T b;
        T a;
    };
}
