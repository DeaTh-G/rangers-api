#pragma once

namespace app::game {
    class MyApplication;
    class ApplicationExtension
        : public hh::fnd::BaseObject
        , public hh::game::GameManagerListener
    {
        MyApplication* application;
    
    public:
        virtual uint64_t GetNameHash() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
    };
}
