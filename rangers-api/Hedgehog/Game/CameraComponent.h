#pragma once

namespace hh::game {
    class CameraManager;
    class CameraComponent : public fnd::ReferencedObject {
    public:
        struct CreateInfo {
            int viewportId;
            int unk2;
            const char* name;
        };

    private:
        char viewportId;
        char unk2;
        char unk3;
        CameraManager* cameraManager;
    public:
        gfnd::ViewportData viewportData;
        csl::ut::VariableString name;

        CameraComponent(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
        static CameraComponent* Create(csl::fnd::IAllocator* allocator, const CreateInfo& createInfo, CameraManager* cameraManager);
    };
}
