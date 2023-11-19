#pragma once

namespace app::save {
    class SaveManagerListener {
    public:
        virtual ~SaveManagerListener() = default;
        virtual void SML_UnkFunc1() {}
        virtual void SML_UnkFunc2() {}
        virtual void SML_UnkFunc3() {}
    };
}
