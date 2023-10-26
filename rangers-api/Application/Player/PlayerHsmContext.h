#pragma once

namespace app::player {
    class PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener {
        class OutOfControlTimerList : public PlayerCounterTimer {
            PlayerHsmContext* pPlayerHsmContext;
        public:
            OutOfControlTimerList(csl::fnd::IAllocator* pAllocator);
        };

        class DamagedObjects : public hh::fnd::BaseObject {
            csl::ut::MoveArray<void*> objects;
        public:
            DamagedObjects(csl::fnd::IAllocator* pAllocator);
        };

        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        csl::ut::MoveArray<void*> unk8;
        OutOfControlTimerList* pOutOfControlTimerList;
        DamagedObjects* pDamagedObjects;
    public:
        PlayerHsmContext(csl::fnd::IAllocator* pAllocator);
        ~PlayerHsmContext();
    };
}
