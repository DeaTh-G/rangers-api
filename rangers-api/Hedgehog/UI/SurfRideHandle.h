#pragma once

namespace hh::ui {
    class SurfRideHandleBase {

    };

    template<typename T>
    class SurfRideHandle : public SurfRideHandleBase, public GOCSpriteListener {

    };

    class SurfRideCastHandle : public SurfRideHandle<SurfRide::Cast> {

    };
}
