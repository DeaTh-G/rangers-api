#pragma once

namespace hh::hid {
    class Vibration : public InputDevice {
    public:
        Vibration(csl::fnd::IAllocator* pAllocator);
    };
}
