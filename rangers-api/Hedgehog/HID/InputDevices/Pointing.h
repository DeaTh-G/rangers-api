#pragma once

namespace hh::hid {
    class Pointing : public InputDevice {
    public:
        Pointing(csl::fnd::IAllocator* pAllocator);
    };
}
