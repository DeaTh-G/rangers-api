#pragma once

namespace app {
    class MyApplication : public hh::game::GameApplication {
        csl::ut::MoveArray<game::ApplicationExtension*> extensions;
    public:
        MyApplication(csl::fnd::IAllocator* pAllocator, hh::fw::FrameworkEnvironment* frameworkEnvironment);
        static MyApplication* Create(hh::fw::FrameworkEnvironment* frameworkEnvironment, csl::fnd::IAllocator* pAllocator);

        void AddExtension(game::ApplicationExtension* extension);
        void RemoveExtension(game::ApplicationExtension* extension);

        virtual void UnkFunc1();
        virtual void UnkFunc2();
        virtual void UnkFunc4();
        virtual void UnkFunc5();
        virtual uint64_t UnkFunc9();

        inline game::ApplicationExtension* GetExtension(const char* name) {
            for (auto* extension : extensions) {
                if (extension->GetNameHash() == csl::ut::HashString(name)) {
                    return extension;
                }
            }
            return nullptr;
        }

        template<typename T>
        inline T* GetExtension() {
            return static_cast<T*>(GetExtension(T::name));
        }
    };
}
