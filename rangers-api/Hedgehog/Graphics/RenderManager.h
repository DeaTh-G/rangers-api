#pragma once

namespace hh::gfx {
    class RenderManager : public fnd::ReferencedObject {
    public:
        struct SModelCreationInfo {
            // Check GOCVisualModelImpl::Setup
            fnd::ManagedResource* unk325; // suspected
            fnd::ManagedResource* unk326; // suspected
            fnd::ManagedResource* unk327; // suspected
            void* unk1;
        };

    public:
        static RenderManager* instance;

        void CreateModelFromResource2(needle::Model** model, const SModelCreationInfo& modelCreationInfo);
        needle::ModelInstance* CreateModelInstance(needle::Model* model, const SModelCreationInfo& modelCreationInfo) const;
        needle::RenderingDevice* GetNeedleResourceDevice();
    };
}
