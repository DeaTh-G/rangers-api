#pragma once

namespace hh::game {
    class CameraManager;
    class CameraComponent : public fnd::ReferencedObject {
    public:
        struct CreateInfo {
            int viewportId;
            int priority;
            const char* name;
        };

        char viewportId;
        char priority;
        char unk3;
        CameraManager* cameraManager;
        gfnd::ViewportData viewportData;
        csl::ut::VariableString name;

        CameraComponent(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
        static CameraComponent* Create(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
    };
}
