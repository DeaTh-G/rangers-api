#pragma once

namespace app::level {
    class LevelInfo : public hh::game::GameService, public save::SaveManagerListener {
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(char);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(char);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(uint32_t);
        UNKNOWN(void*);
        UNKNOWN(void*);
        UNKNOWN(csl::ut::MoveArray<void*>);
        UNKNOWN(uint16_t);
        UNKNOWN(char);
        UNKNOWN(void*);
    public:
        ~LevelInfo(){}
		virtual void* GetClassId();
    };
}