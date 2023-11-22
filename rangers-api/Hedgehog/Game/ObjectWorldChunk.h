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

	// If spawntype is ETERNAL or EXTRINSIC, then don't spawn, otherwise spawn.
	bool IsSpawnBySpawnType(const GameObjectClass* gameObjectClass);

    bool GetStatusEternal(const GameObjectClass* gameObjectClass, int* type);
    bool GetStatusExtrinsic(const GameObjectClass* gameObjectClass, int* type);

    class ObjectWorld;
    class ObjectWorldChunk : public fnd::ReferencedObject, public GameManagerListener {
        enum class Flag : uint8_t {
            EDITOR,
        };

        typedef bool (*ObjectAttribute)(const GameObjectClass* gameObjectClass, int* attributeFlags);

        uint64_t unk1;
        GameManager* gameManager;
        csl::ut::Bitset<Flag> flags;
        csl::ut::MoveArray<ObjectWorldChunkListener*> listeners;
        csl::ut::MoveArray<ObjectWorldChunkLayer*> layers;
        csl::ut::StringMap<ObjectWorldChunkLayer*> layersByName;
        csl::ut::MoveArray<GameObject*> objects;
        csl::ut::MoveArray<WorldObjectStatus> objectStatuses;
        csl::ut::StringMap<WorldObjectStatus*> objectStatusesByName;
        hh::game::ObjectMap<int> objectIndicesByObjectId;
        csl::ut::PointerMap<GameObjectClass*, csl::ut::MoveArray<GameObject*>*> objectsByClass;
        csl::ut::MoveArray<void*> unk11;
    public:
        ObjectWorldChunk(csl::fnd::IAllocator* allocator, GameManager* gameManager);
        void AddLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayerAll();
        const csl::ut::MoveArray<ObjectWorldChunkLayer*>& GetLayers() const;
        void SetLayerEnabled(const char* name, bool enabled);

        ObjectWorldChunkLayer* GetLayerByName(const char* name) const;

        void AddWorldObjectStatus(ObjectData& objectData, bool enabled, int spawnPriority);

        void AddListener(ObjectWorldChunkListener* listener);
        void RemoveListener(ObjectWorldChunkListener* listener);
        void Despawn(const ObjectData* objectData); // inlined :/
        void DespawnByIndex(int index);
        ObjectDataAccessor GetObjectDataByObjectId(ObjectId id) const;
        ObjectDataAccessor GetObjectDataByName(const char* name) const;
        GameObject* SpawnByObjectId(ObjectId id);
        GameObject* SpawnByIndex(int index, ObjectAttribute filter);
        GameObject* SpawnByAttribute(ObjectAttribute filter);

        GameObject* GetGameObjectByObjectId(ObjectId id) const;
        WorldObjectStatus GetWorldObjectStatusByObjectId(ObjectId id) const;

        inline const csl::ut::MoveArray<WorldObjectStatus>& GetObjectStatuses() const {
            return objectStatuses;
        }

        inline int GetObjectIndexById(ObjectId id) const {
            return objectIndicesByObjectId.GetValueOrFallback(id, -1);
        }

        inline GameObject* GetObjectByIndex(int i) const {
            return objects[i];
        }

        inline WorldObjectStatus GetWorldObjectStatusByIndex(int i) const {
            return objectStatuses[i];
        }

        inline void DespawnAll() {
            for (int i = 0; i < objects.size(); i++) {
                DespawnByIndex(i);
            }
        }
        
        inline void Restart(bool force) {
            if (force) {
                for (int i = 0; i < objects.size(); i++) {
                    objectStatuses[i].Restart();
                }
            }
            else {
                for (int i = 0; i < objects.size(); i++) {
                    if (!objectStatuses[i].IsNoRestart())
                        objectStatuses[i].Restart();
                }
            }
        }

        inline void ShutdownPendingObjects() {
            gameManager->ShutdownPendingObjects();
        }

        inline void SetEditorStatus(bool status) {
            flags.set(Flag::EDITOR, status);
        }
        inline bool IsStatusEditor() {
            return flags.test(Flag::EDITOR);
        }
    };
}
