#pragma once

namespace app::snd {
    class CustomSoundListener {
    public:
        virtual ~CustomSoundListener();
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
    };
}
