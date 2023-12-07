#pragma once

namespace hh::gfx {
    class GOCVisualDebugDraw : public GOCVisualTransformed {
    public:
        struct DebugGeometryDefinition {
            csl::ut::MoveArray<csl::math::Vector3> vertices;
            csl::ut::MoveArray<fnd::Triangle> triangles;
        public:
            DebugGeometryDefinition(csl::fnd::IAllocator* allocator) : vertices{ allocator }, triangles{ allocator } {}
        };

        struct SetupInfo {
            void* unk1;
            uint16_t unk2;
            DebugGeometryDefinition* geomDef;
            uint64_t unk3;
            uint64_t unk4;
            csl::ut::Color<uint8_t> color;
            uint8_t unk6;
        };

    public:
        inline GOCVisualDebugDraw(csl::fnd::IAllocator* allocator) : GOCVisualTransformed{ allocator } {
            gocEventMask.m_dummy = static_cast<GOCEventMask>(5);
        }
        void Setup(const SetupInfo& setupInfo);

		virtual void* GetClassId() override;
        virtual void OnGOCVisualEvent(int unkParam1, unsigned int unkParam2, void* unkParam3) override {}
        
        GOCOMPONENT_CLASS_DECLARATION(GOCVisualDebugDraw)
    };
}
