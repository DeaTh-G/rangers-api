#pragma once

namespace hh::fnd {
    template<size_t size>
    class InplaceUri : public Uri {
        csl::ut::InplaceMoveArray<char, size - 1> buffer;
    };
}
