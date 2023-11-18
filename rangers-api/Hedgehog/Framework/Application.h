#pragma once

namespace hh::fw {
    class ApplicationListener {
    public:
        virtual ~ApplicationListener() = default;
        virtual void AL_UnkFunc1();
    };

    class Application : public hh::fnd::ReferencedObject, hh::fw::KeyEventHandler, hh::fw::MouseEventHandler {
    public:
        FrameworkEnvironment* frameworkEnvironment;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;

        static Application* instance;
        Application(csl::fnd::IAllocator* pAllocator, FrameworkEnvironment* frameworkEnvironment);

        inline static Application* GetInstance() {
            return RESOLVE_STATIC_VARIABLE(instance);
        }

        void AddListener(ApplicationListener* listener);
        void RemoveListener(ApplicationListener* listener);
        void AddMouseEventHandler(MouseEventHandler* handler, uint32_t unkParam1);
        void RemoveMouseEventHandler(MouseEventHandler* handler);

        virtual void Startup() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void Reset() {}
        virtual void Shutdown() {}
        virtual uint64_t UnkFunc9() { return 0; }
    };
}
