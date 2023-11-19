#pragma once

namespace app::level {
    class LevelInfo : public hh::game::GameService, public save::SaveManagerListener {
        void* unk5;
        void* unk6;
        char unk7;
        void* unk8;
        void* unk9;
        void* unk10;
        char unk11;
        void* unk12;
        void* unk13;
        void* unk14;
        void* unk15;
        uint32_t unk16;
        void* unk17;
        void* unk18;
        csl::ut::MoveArray<void*> unk19;
        uint16_t unk20;
        char unk21;
        void* unk22;
    public:
        virtual void* GetClassId();
		virtual void OnAddedToGame();
		virtual void OnRemovedFromGame();
        virtual void SML_UnkFunc1();

        GAMESERVICE_CLASS_DECLARATION(LevelInfo)
    };
}