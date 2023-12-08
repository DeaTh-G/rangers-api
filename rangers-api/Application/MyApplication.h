#pragma once

namespace app {
    class MyApplication : public hh::game::GameApplication {
        csl::ut::MoveArray<game::ApplicationExtension*> extensions;
    public:
        MyApplication(csl::fnd::IAllocator* pAllocator, hh::fw::FrameworkEnvironment* frameworkEnvironment);
        static MyApplication* Create(hh::fw::FrameworkEnvironment* frameworkEnvironment, csl::fnd::IAllocator* pAllocator);

        void AddExtension(game::ApplicationExtension* extension);
        void RemoveExtension(game::ApplicationExtension* extension);

        virtual void Startup() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual uint64_t UnkFunc9() override;

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
