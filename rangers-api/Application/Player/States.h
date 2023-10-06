#pragma once

namespace app::player {
    class PlayerStateActionBase : public PlayerStateBase {

    };

    class StateJumpBase : public PlayerStateActionBase {

    };

    class StateJump : public StateJumpBase {
        virtual void ProcessMessage(void* hsm, const hh::fnd::Message& message);
        virtual void UnkFunc12();
        virtual void UnkFunc13();
        virtual void Update();
    };
}