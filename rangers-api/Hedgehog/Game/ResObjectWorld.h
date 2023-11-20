#pragma once

namespace hh::game {
    struct alignas(16) ObjectId {
        uint8_t objectId;
        uint8_t groupId;

        inline bool operator==(const ObjectId& other) const {
            return objectId == other.objectId && groupId == other.groupId;
        }

        inline bool operator!=(const ObjectId& other) const {
            return !operator==(other);
        }
    };

    struct ComponentData {
        uint64_t unk1;
        const char* type;
        uint64_t size;
        void* data;
    };

    struct ObjectTransformData {
        csl::math::Position position;
        csl::math::Position rotation;
    };

    struct ObjectData {
        uint32_t unk1;
        uint32_t unk2;
        const char* gameObjectClass;
        const char* name;
        ObjectId id;
        ObjectId parentID;
        ObjectTransformData transform;
        ObjectTransformData localTransform;
        csl::ut::MoveArray<ComponentData*> componentData;
        void* objInfo;
    };

    struct ObjectWorldData {
        uint32_t unk1;
        uint32_t unk2;
        uint64_t unk3;
        csl::ut::MoveArray<ObjectData*> objects;
    };

    class ResObjectWorld : public fnd::ManagedResource {
    public:
        ObjectWorldData* binaryData;
        virtual void Load(void* data, size_t size);
        const csl::ut::MoveArray<ObjectData*>& GetObjects() const;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResObjectWorld)
    };
}
