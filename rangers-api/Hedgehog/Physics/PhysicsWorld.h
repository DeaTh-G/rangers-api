#pragma once

namespace hh::physics {
    class PhysicsWorldListener {
    public:
        virtual ~PhysicsWorldListener() = default;
        virtual void PWL_UnkFunc1() {}
        virtual void PWL_UnkFunc2() {}
        virtual void PWL_UnkFunc3() {}
        virtual void PWL_UnkFunc4() {}
        virtual void PWL_UnkFunc5() {}
        virtual void PWL_UnkFunc6() {}
    };
    // class PhysicsWorld : public game::GameService {

    // };
}