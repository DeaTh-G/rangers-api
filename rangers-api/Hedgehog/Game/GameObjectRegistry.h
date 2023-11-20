#pragma once

namespace hh::game
{
    class GameObjectRegistry : fnd::BaseObject {
        csl::ut::MoveArray<const GameObjectClass*> gameObjectClasses;
        csl::ut::StringMap<const GameObjectClass*> gameObjectClassesByName;
    public:
        GameObjectRegistry(csl::fnd::IAllocator* pAllocator);
        void AddObject(const GameObjectClass* gameObjectClass);
        const GameObjectClass* GetGameObjectClassByName(const char* name);
    };
}
