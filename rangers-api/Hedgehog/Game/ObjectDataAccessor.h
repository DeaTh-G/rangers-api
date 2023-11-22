#pragma once

namespace hh::game {
    struct ObjectDataAccessor {
        const GameObjectClass* gameObjectClass;
        ObjectData* objectData;

        ObjectDataAccessor(const GameObjectClass* gameObjectClass, ObjectData* objectData);
    };
}
