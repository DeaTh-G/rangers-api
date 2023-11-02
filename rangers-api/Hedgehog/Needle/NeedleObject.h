#pragma once

namespace hh::needle {
    class NeedleObject {
        uint32_t pad;
    public:
        NeedleObject(csl::fnd::IAllocator* allocator);
        virtual ~NeedleObject() = default;
    };
}
