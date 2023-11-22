#pragma once

namespace hh::game {
    struct ObjectId {
        uint64_t objectId;
        uint64_t groupId;

        inline bool operator==(const ObjectId& other) const {
            return objectId == other.objectId && groupId == other.groupId;
        }

        inline bool operator!=(const ObjectId& other) const {
            return !operator==(other);
        }
    };
}