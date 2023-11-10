#pragma once

namespace hh::game {
    struct GameUpdaterConfig {
        GameManager* gameManager;
        int unk1;
        uint32_t unk2;
        uint32_t unk3;
        uint32_t unk4;
    };

    class GameUpdater : public fnd::ReferencedObject {
    public:
        enum class Flags : uint8_t {
            INGAME_PAUSE = 0,
            DEBUG_PAUSE = 1,
            DEBUG_STEP_FRAME = 4,
            OBJECT_PAUSE = 5,
        };

        struct Unk1 {
            struct Unk3 {
                csl::fnd::IAllocator* allocator;
                void* buffer;
                uint32_t unk1;
                uint32_t unk2;
            };

            Unk3 unk1; // buffer is 0xC000 size
            Unk3 unk2; // buffer is 0x10000 size
            void* unk7[2]; // function pointers assigned in constructor
        public:
            Unk1(csl::fnd::IAllocator* allocator);
        };

        struct Unk2 {
            float deltaTime;
            uint32_t currentFrame;
            uint16_t unk2;
            uint32_t unk3;
        public:
            Unk2();
        };
    
    // private:
        csl::ut::Bitset<Flags> flags;
        uint32_t layersActiveDuringNormalOperation;
        uint32_t layersActiveDuringIngamePause;
        uint32_t layersActiveDuringDebugPause;
        uint32_t layersActiveDuringObjectPause;
        float unk5;
        float maybeFrameTimes[32];
        float unk6;
        GameManager* gameManager;
        uint64_t unk6b;
        uint64_t unk6c;
        Unk1 unk7;
        Unk2 unk8[32];
        csl::ut::MoveArray<void*> unk9;
        uint32_t unk10;
    
    public:
        GameUpdater(csl::fnd::IAllocator* allocator, const GameUpdaterConfig& config);

        // inline bool GetRunning() const {
        //     return flags.test(Flags::RUNNING);
        // }

        // inline void SetRunning(bool state) {
        //     flags.set(Flags::RUNNING, state);
        // }

        // inline void ToggleRunning() {
        //     flags.flip(Flags::RUNNING);
        // }
    };
}
