#pragma once

namespace hh::needle {
    class SupportFX {
    public:
        class CaptureIBLListener {
        public:
            virtual ~CaptureIBLListener() = default;
            virtual void CIL_UnkFunc1();
            virtual void CIL_UnkFunc2();
        };
    };
    class SupportFXAll : public SupportFX {};
}
