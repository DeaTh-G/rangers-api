#pragma once

namespace hh::game {
    class WorldObjectStatus {
    public:
        // This is all very speculative
        enum class Flag : uint8_t {
            ENABLED,
            IS_ALIVE,
            STARTED,
            NO_RESTART,
        };

        ObjectData* objectData;
        csl::ut::Bitset<Flag> flags;
        uint32_t unk3;
        int spawnPriority;
        virtual ~WorldObjectStatus() = default;

        inline bool IsStarted() {
            return flags.test(Flag::STARTED);
        }

        inline bool IsNoRestart() {
            return flags.test(Flag::NO_RESTART);
        }

        inline void Restart() {
            flags.reset(Flag::STARTED);
        }
    };
}
