#pragma once

namespace hh::ut {
    template<typename T = char>
    class TempString : public csl::ut::BasicString<T> {
        csl::ut::InplaceMoveArray<T, 127> buffer{ fnd::GetTempAllocator() };
    };
}
