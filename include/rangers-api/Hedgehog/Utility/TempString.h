#pragma once

namespace hh::ut {
    template<typename T = char>
    class TempString {
        csl::ut::InplaceMoveArray<T, 127> buffer{ hh::fnd::GetTempAllocator() };
    };
}
