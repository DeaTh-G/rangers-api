#pragma once

namespace hh::game {
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
        csl::ut::VariableString name;
        ObjectId id;
        ObjectId parentID;
        ObjectTransformData transform;
        ObjectTransformData localTransform;
        csl::ut::MoveArray<ComponentData*> componentData;
        void* objInfo;

        ObjectData(csl::fnd::IAllocator* allocator, const GameObjectClass* gameObjectClass, const char* name, ObjectData* parent, const ObjectTransformData& localTransform)
            : name{ name, allocator }
            , gameObjectClass{ gameObjectClass->pName }
            , localTransform { localTransform }
            , componentData{ allocator } {
            std::mt19937_64 mt;
            id.groupId = mt();
            id.objectId = mt();
            
            if (parent) {
                parentID = parent->id;
                // transform = Eigen::
            } else {
                parentID = { 0, 0 };
                transform = localTransform;
            }

            objInfo = hh::fnd::RflTypeInfoRegistry::GetInstance()->ConstructObject(allocator, gameObjectClass->rflClass->GetName());
        }
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

        inline void AddObject(ObjectData* objData) {
            if (binaryData->objects.get_allocator() == nullptr)
                binaryData->objects.change_allocator(GetAllocator());

            binaryData->objects.push_back(objData);
        }

        MANAGED_RESOURCE_CLASS_DECLARATION(ResObjectWorld)
    };
}
