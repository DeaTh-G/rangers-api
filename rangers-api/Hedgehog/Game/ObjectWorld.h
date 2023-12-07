#pragma once

namespace hh::game {
    class ObjectWorldListener {
    public:
        virtual ~ObjectWorldListener() = default;
        virtual void WorldChunkAddedCallback(ObjectWorldChunk* chunk) {}
        virtual void WorldChunkRemovedCallback(ObjectWorldChunk* chunk) {}
    };

    class ObjectWorld : public GameService, public GameStepListener {
        csl::ut::MoveArray<ObjectWorldChunk*> worldChunks;
        csl::ut::MoveArray<ObjectWorldListener*> listeners;
        csl::ut::MoveArray<ObjectWorldExtension*> extensions;
        uint64_t unk104;
        uint8_t unk105; //flags? 0 = LEVEL_STARTED, 1 = EDITOR_STARTED

    public:
		virtual void* GetClassId() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void Update(const fnd::SUpdateInfo& updateInfo) override;

        csl::ut::MoveArray<ObjectWorldChunk*>& GetWorldChunks() const;
        void AddWorldChunk(ObjectWorldChunk* chunk);
        void RemoveWorldChunk(ObjectWorldChunk* chunk);
        void RemoveWorldChunkAll();
        void AddWorldListener(ObjectWorldListener* chunk);
        void RemoveWorldListener(ObjectWorldListener* chunk);
        void AddWorldExtension(ObjectWorldExtension* chunk);
        void RemoveWorldExtension(ObjectWorldExtension* chunk);
        void RemoveWorldExtensionAll();
        void GetObjectDataByObjectId(ObjectId objectId) const;
        void GetGameObjectHandleByObjectId(ObjectId objectId) const;
        // void SendObjectMessageImm(ObjectId objectId, fnd::Message& msg, const GameObjectHandleBase& handle, bool unkParam);
        void SpawnObjectBySetObjectID(ObjectId objectId) const;
        void LevelStarted();
        void LevelEnded();
        void EditorStarted();
        void EditorEnded();

        GAMESERVICE_CLASS_DECLARATION(ObjectWorld)
    };
}
