#pragma once

namespace csl::ut {
    // No, this alignas is not a bug, this is actually how the game works!
    template<typename T>
    struct alignas(4) Color {
        T a;
        T b;
        T g;
        T r;

        inline bool operator==(const Color<T>& other) {
            return r == other.r && g == other.g && b == other.b && a == other.a;
        }

        inline bool operator!=(const Color<T>& other) {
            return !operator==(other);
        }
    };
}
