#pragma once

namespace hh::fnd {
    template<size_t size>
    class TempInplaceUri : public InplaceUri<size> {
    public:
        TempInplaceUri() : InplaceUri<size>{ GetTempAllocator(GetAllocatorSystem()) } {};
    };
}
