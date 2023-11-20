#pragma once

namespace hh::game {
	struct WorldObjectCInfo {
		csl::ut::InplaceMoveArray<hh::game::GOComponentConfiguration, 5> componentConfig;
		uint64_t unk1; // see 1.40 0x140D48348
	};

    class ObjectWorldChunkListener {
    public:
        virtual ~ObjectWorldChunkListener() = default;
    };

    class ObjectWorld;
    class ObjectWorldChunk : public fnd::ReferencedObject, public GameManagerListener {
        enum class Flag : uint8_t {
            EDITOR,
        };

        uint64_t unk1;
        GameManager* gameManager;
        csl::ut::Bitset<Flag> flags;
        csl::ut::MoveArray<ObjectWorldChunkListener*> listeners;
        csl::ut::MoveArray<ObjectWorldChunkLayer*> layers;
        csl::ut::StringMap<ObjectWorldChunkLayer*> layersByName;
        csl::ut::MoveArray<GameObject*> objects;
        csl::ut::MoveArray<WorldObjectStatus> objectStatuses;
        csl::ut::StringMap<void*> unk8;
        hh::game::ObjectMap<int> objectIndicesByObjectId;
        csl::ut::PointerMap<GameObjectClass*, csl::ut::MoveArray<GameObject*>*> objectsByClass;
        csl::ut::MoveArray<void*> unk11;
    public:
        ObjectWorldChunk(csl::fnd::IAllocator* allocator, GameManager* gameManager);
        void AddLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayerAll();
        inline const csl::ut::MoveArray<ObjectWorldChunkLayer*>& GetLayers() const {
            return layers;
        }
        void SetLayerEnabled(const char* name, bool enabled);

        void AddWorldObjectStatus(ObjectData& objectData, bool enabled, int spawnPriority);

        void AddListener(ObjectWorldChunkListener* listener);
        void RemoveListener(ObjectWorldChunkListener* listener);
        void Despawn(const ObjectData* objectData); // inlined :/
        void DespawnByIndex(int index);

        inline const csl::ut::MoveArray<WorldObjectStatus>& GetObjectStatuses() const {
            return objectStatuses;
        }

        inline void SetEditorStatus(bool status) {
            flags.set(Flag::EDITOR, status);
        }
        inline bool IsStatusEditor() {
            return flags.test(Flag::EDITOR);
        }
    };
}
