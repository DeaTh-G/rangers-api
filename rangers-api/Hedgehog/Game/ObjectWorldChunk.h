#pragma once

namespace hh::game {
    class ObjectWorldChunkListener {
    public:
        virtual ~ObjectWorldChunkListener() = default;
    };

    class ObjectWorld;
    class ObjectWorldChunk : public fnd::ReferencedObject, public GameManagerListener {
        uint64_t unk1;
        GameManager* gameManager;
        uint8_t unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<ObjectWorldChunkLayer*> layers;
        csl::ut::StringMap<ObjectWorldChunkLayer*> layersByName;
        csl::ut::MoveArray<void*> unk6;
        csl::ut::MoveArray<void*> unk7;
        csl::ut::StringMap<void*> unk8;
        hh::game::ObjectMap<int> objectIndicesByObjectId;
        csl::ut::PointerMap<GameObjectClass*, csl::ut::MoveArray<GameObject*>*> objectsByClass;
        csl::ut::MoveArray<void*> unk11;
    public:
        ObjectWorldChunk(csl::fnd::IAllocator* allocator, GameManager* gameManager);
        void AddLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayerAll();
        void SetLayerEnabled(const char* name, bool enabled);
        void AddListener(ObjectWorldChunkListener* listener);
        void RemoveListener(ObjectWorldChunkListener* listener);
    };
}
