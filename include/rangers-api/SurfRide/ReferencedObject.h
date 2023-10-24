#pragma once

namespace SurfRide {
    class ReferencedObject : public Base {
		uint16_t RefCount{};
    public:
        void Free();
    };
}
