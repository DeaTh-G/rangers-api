#pragma once

namespace hh::ui {
    class LayerController;
    class GOCSprite : public game::GOComponent {
        class Renderable : public gfnd::Renderable {
            GOCSprite* gocSprite;
        public:
            Renderable(csl::fnd::IAllocator* pAllocator);
            virtual void UnkFunc1();
        };

        hh::fnd::LogData log1;
        hh::fnd::LogData log2;
        csl::fnd::Delegate<void (GOCSprite*)> OnLayerControllerCreated;
        uint64_t field_E0;
        SurfRide::Project* project;
        hh::ui::ResSurfRideProject* projectResource;
        csl::ut::VariableString projectName;
        bool initialized;
        SurfRideProjectContext* projectContext;
        csl::ut::MoveArray<LayerController*> layerControllers;
        csl::ut::MoveArray<void*> field_138;
        csl::ut::MoveArray<void*> field_158;
        uint64_t renderable;
        bool field_180;
        uint16_t nextId;
        uint32_t field_184;
        uint32_t field_188;
        uint64_t field_190;
        uint64_t field_198;
        uint64_t field_1A0;
        uint64_t field_1A8;
        csl::ut::MoveArray<SurfRideCastHandle> casts;
        csl::ut::PointerMap<SurfRide::Cast*, SurfRideCastHandle> castMap;
        csl::ut::MoveArray<SurfRideLayerHandle> layers;
        csl::ut::PointerMap<SurfRide::Layer*, SurfRideLayerHandle> layerMap;
        
        static GOCSprite* Create(csl::fnd::IAllocator* pAllocator);

        LayerController* GetLayerController(SurfRide::Layer* layer, uint16_t id);
        fnd::Handle<SurfRideCastHandle> GetCastHandle(SurfRide::Cast* cast);
        fnd::Handle<SurfRideLayerHandle> GetLayerHandle(SurfRide::Layer* layer);
    public:
        struct alignas(8) Config {
            hh::ui::ResSurfRideProject* projectResource;
            const char* name;
            uint32_t unk1;
            uint8_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
        };

        static game::GOComponentClass* GetClass();
        void Initialize(const Config& config);
        LayerController* GetLayerController(const char* sceneName, const char* layerName, uint16_t id);
        LayerController* GetLayerControllerWithNextId(SurfRide::Layer* layer);
        SurfRide::Project* GetProject();
    };
}