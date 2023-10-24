#pragma once

namespace hh::font {
    class TextListener {
    public:
        virtual ~TextListener();
        virtual bool TL_UnkFunc1(void* unkParam1, void* unkParam2) { return false; }
        virtual int TL_UnkFunc2() { return -1; }
    };
}