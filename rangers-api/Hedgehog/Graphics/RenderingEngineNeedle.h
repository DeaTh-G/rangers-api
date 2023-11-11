#pragma once

namespace hh::gfx {
    class RenderingEngineNeedle : public RenderingEngine {
        class Impl : public fnd::ReferencedObject {
        public:
            class ResourceListener : public fnd::ReferencedObject, fnd::ResourceManager::ResourceListener {
                RenderingEngineNeedle* renderingEngine;
                csl::ut::MoveArray<void*> unk1;
            };

            class NeedleShaderListInfo : public fnd::ReferencedObject {
                csl::ut::PointerMap<void*, void*> unk1;
                csl::ut::PointerMap<void*, void*> unk2;
            };
        
        private:
            RenderingEngineNeedle* renderingEngine;
            needle::SupportFX* supportFX;
            needle::RenderingDevice* renderingDevice;
            fnd::Reference<ResourceListener> resourceListener;
            fnd::Reference<NeedleShaderListInfo> shaderListInfo;
            fnd::Reference<needle::PrimitiveRenderer> primitiveRenderer;
            fnd::Reference<NeedleRenderer> renderers[10]; // one created for each in unk1 in graphicscontext
            fnd::Reference<RenderingWorld> world;

        public:
            Impl(csl::fnd::IAllocator* allocator);
        };

        Impl* implementation;

    public:
        RenderingEngineNeedle(csl::fnd::IAllocator* allocator);
        virtual void CreateRenderingDevice(void* unkParam1) override;
        virtual void UnkFunc2() override {}
        virtual uint64_t UnkFunc3(uint64_t unkParam1) override;
        virtual uint64_t UnkFunc4() override {}
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t Startup() override;
        virtual uint64_t Shutdown() override;
        virtual void* GetSomethingInSupportFX1();
        virtual void* GetSomethingInSupportFX2();
        virtual void SetSupportFX(needle::SupportFX* supportFX);
        virtual needle::SupportFX* GetSupportFX();
        virtual void UnkFunc13() {}
        virtual void UnkFunc14() {}
        virtual void UnkFunc15() {}
        virtual void UnkFunc16() {}
        virtual uint64_t CreateRenderTextureHandle(const needle::RenderTextureCreateArgs& createArgs, csl::fnd::IAllocator* allocator);
        virtual uint64_t DestroyRenderTextureHandle(needle::RenderTextureHandle* handle);
        virtual void UnkFunc17() {}
        virtual unsigned int UnkFunc18() { return 0; }
        virtual void UnkFunc19() {}
        virtual uint64_t UnkFunc20();
        virtual void UnkFunc21() {}
        virtual void UnkFunc22() {}
        virtual unsigned int UnkFunc23() { return 0; }
        virtual void UnkFunc24() {}

        void AddComponent(RenderingComponent* component);
    };
}
