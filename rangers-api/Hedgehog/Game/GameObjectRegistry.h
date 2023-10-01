#pragma once

namespace hh::game
{
    class GameObjectRegistry : fnd::BaseObject {
        csl::ut::MoveArray<GameObjectClass*> gameObjects;
        csl::ut::StringMap<GameObjectClass*> gameObjectsByName;
    public:
        GameObjectRegistry(csl::fnd::IAllocator* pAllocator);
        void AddObject(GameObjectClass* gameObjectClass);
    };
}
