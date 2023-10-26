#pragma once

namespace hh::hid {
    class InputDevice : public fnd::ReferencedObject {
    public:
        InputDevice(csl::fnd::IAllocator* pAllocator);

        virtual void* GetClassId();
        virtual uint64_t UnkFunc1();
        virtual float UnkFunc2();
        virtual csl::math::Vector4 UnkFunc3(); // most probably not a vector, but don't know what it really is
        virtual csl::math::Vector4 UnkFunc4();
        virtual void UnkFunc5();
        virtual bool UnkFunc6() { return true; }
        virtual bool UnkFunc7() { return false; } 
    };
}
