#pragma once

namespace hh::game {
    class WorldObjectStatus {
    public:
        enum class Flag : uint8_t {
            ENABLED,
            CAN_BE_KILLED,
        };

        ObjectData* objectData;
        csl::ut::Bitset<Flag> flags;
        uint32_t unk3;
        int spawnPriority;
        virtual ~WorldObjectStatus() = default;
    };
}