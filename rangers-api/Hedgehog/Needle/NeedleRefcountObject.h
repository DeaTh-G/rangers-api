#pragma once

namespace hh::needle {
    class NeedleRefcountObject : public NeedleObject {
        uint32_t refCount;
    };
}
