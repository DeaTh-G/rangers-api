#pragma once

namespace hh::fw {
    class Application;
    class BaseFramework {
        fnd::Reference<Application> application;
        uint32_t unk2;
        uint64_t unk3[9];
        uint32_t unk4;
        csl::ut::InplaceMoveArray<void*, 10> unk5;
        csl::ut::InplaceMoveArray<void*, 10> unk6;
        bool (*unk7)(void* unkParam1, int unkParam2, void* unkParam3);
        bool unk8;
    public:
        BaseFramework(csl::fnd::IAllocator* allocator);
        virtual ~BaseFramework() = default;
        virtual uint64_t UnkFunc1() {}
        virtual uint64_t UnkFunc2() {}
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4(FrameworkEnvironment& frameworkEnvironment) = 0;
        virtual uint64_t UnkFunc5() = 0;
    };
}
