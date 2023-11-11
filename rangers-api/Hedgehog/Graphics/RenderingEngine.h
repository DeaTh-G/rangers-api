#pragma once

namespace hh::gfx {
    class RenderingEngine : public fnd::ReferencedObject {
        csl::ut::MoveArray<RenderingComponent*> components;
        bool callUnkFunc1OnNewComponents;
    public:
        RenderingEngine(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetModelGatherBufferSize();
        virtual void CreateRenderingDevice(void* unkParam1) = 0;
        virtual void UnkFunc2() = 0;
        virtual uint64_t UnkFunc3(uint64_t unkParam1) = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t Startup() = 0;
        virtual uint64_t Shutdown() = 0;
        virtual uint64_t UnkFunc8();
    };
}
