#pragma once

namespace hh::anim {
    class SkeletalMeshBinding;
}

namespace hh::gfx {
    // Actually called GOCVisualMode::Description but I'm not sure how to resolve the mutual dependency with Setup.
    // Assumed, some of these fields may not be part of this but of the GOCVisualModel instead
    struct GOCVisualModelDescription {
        enum class Flag {
            SCENE_EDITOR_RENDER = 0x14,
            NO_CONTROL_RENDER_OPTION = 0x15,
            RENDER_COLOR_MASK = 0x16,
            NO_SHADOW_RECEIVE = 0x17,
            NO_SHADOW_CAST = 0x18,
            NO_MATERIAL_OPTIMIZE = 0x19,
            UNK1 = 0x1A, // Assigned in GOCVisualModelImpl::Setup
            UNK2 = 0x1B,
            IS_HEIGHTMAP_REACTOR = 0x1C,
            IS_SHADOW_RECEIVE = 0x1D,
            IS_SHADOW_CASTER = 0x1E,
        };
        uint64_t unk317;
        uint16_t unk318;
        uint64_t unk319;
        uint64_t unk320;
        uint64_t skeletalAnimationRelatedUnk;
        csl::ut::Bitset<Flag> flags;
        uint32_t unk322;
        int unk323;
        uint64_t unk324;
        fnd::ManagedResource* unk325;
        fnd::ManagedResource* unk326;
        fnd::ManagedResource* unk327;
        bool isSky;
        bool isOccluder;
        bool disableColorDraw;
        bool useGIPRT;
        bool useGISG;
        uint32_t unk330;
        uint32_t useSkeletalAnimRelated;
        uint16_t unk331;

        GOCVisualModelDescription(csl::fnd::IAllocator* allocator);
    };

    class GOCVisualModel;
    class GOCVisualModelImpl {
    public:
        struct Unk1 {
            uint8_t unk1;
            uint8_t unk2;
            uint32_t unk3[64];
            uint8_t unk4;
        };

    private:
        needle::PBRModelInstance* modelInstance;
        csl::fnd::IAllocator* allocator;
        uint16_t unk2;
        int unk3;
        uint32_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk6b;
        uint64_t unk6c;
        uint64_t unk6d;
        uint32_t unk7;
        int unk8;
        float scale;
        Unk1 unk10;
        uint64_t unk11;
        uint64_t unkpad[67];

    public:
        GOCVisualModelImpl(csl::fnd::IAllocator* allocator);
        uint64_t OnGOCVisualEvent(GOCVisualModel* visualModel, int unkParam1, unsigned int unkParam2, void* unkParam3);
        void Setup(GOCVisualModel& model, const GOCVisualModelDescription& description);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
    };

    class GOCVisualModel : public GOCVisualTransformed {
        GOCVisualModelImpl* pImplementation;
        GOCVisualModel* masterPoseComponent;
        csl::ut::InplaceMoveArray<GOCVisualModel*, 3> poseComponents;
        uint32_t unk303;
        fnd::ManagedResource* unk304;
        uint64_t unk305;
        uint64_t unk306;
        uint64_t unk307;
        uint64_t unk308;
        uint64_t unk309;
        uint64_t unk310;
        uint32_t unk311;
        uint8_t unk312;
        uint64_t unk313;
        uint64_t unk314;
        fnd::Reference<anim::SkeletalMeshBinding> skeletalMeshBinding;
        float unk316;
        GOCVisualModelDescription description;
        GOCVisualModelImpl implementation;
        uint64_t unk332;

    public:
		virtual void* GetClassId() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void LoadReflection(const fnd::RflClass& rflClass) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(int unkParam1, unsigned int unkParam2, void* unkParam3) override;
        void SetMasterPoseComponent(GOCVisualModel* component);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualModel)
    };
}
