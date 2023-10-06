#pragma once

namespace hh::ut {
    namespace internal {
        class StateImpl : public fnd::ReferencedObject {
            virtual void UnkFunc1();
            virtual void UnkFunc2();
            virtual void UnkFunc3();
            virtual void UnkFunc4();
            virtual void UnkFunc5();
            virtual void UnkFunc6();
            virtual void UnkFunc7();
            virtual void UnkFunc8();
            virtual void UnkFunc9();
            virtual void UnkFunc10();
            virtual void ProcessMessage(void* hsm, const hh::fnd::Message& message);
            virtual void UnkFunc11() { return false; }
            virtual void UnkFunc15();
            virtual void Start() { return false; }
            virtual void Exit() { return false; }
            virtual void UnkFunc12();
            virtual void UnkFunc13();
            virtual void UnkFunc14();
            virtual void Update() { return false; }
        };
    }

    template<typename T>
    class StateBase : public internal::StateImpl {

    };
}