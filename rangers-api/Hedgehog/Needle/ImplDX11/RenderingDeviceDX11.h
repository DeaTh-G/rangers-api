#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class RenderingDeviceDX11 {
        public:
            void* unk[3];
            DeviceObjectDX11* deviceObject;
            virtual ~RenderingDeviceDX11();
            virtual uint32_t UnkFunc1() { return 0; }
            virtual void UnkFunc2();
            virtual void UnkFunc3();
            virtual void UnkFunc4();
            virtual void UnkFunc5() {}
            virtual uint32_t UnkFunc6() { return 0; }
            virtual bool UnkFunc7() { return false; }
            virtual void UnkFunc8();
            virtual void UnkFunc9();
            virtual void UnkFunc10();
            virtual Texture* CreateTexture2D();
            virtual void UnkFunc11();
            virtual void UnkFunc12();
            virtual void UnkFunc13();
            virtual void UnkFunc14();
            virtual void UnkFunc15();
            virtual void UnkFunc16();
            virtual void UnkFunc17();
            virtual void UnkFunc18();
            virtual void UnkFunc19();
            virtual void UnkFunc20() {}
            virtual void UnkFunc21() {}
            virtual void UnkFunc22();
            virtual void UnkFunc23();
            virtual void UnkFunc24();
            virtual void UnkFunc25();
            virtual void UnkFunc26();
            virtual void UnkFunc27();
            virtual void UnkFunc28();
            virtual void UnkFunc29();
            virtual void UnkFunc30();
            virtual void UnkFunc31();
            virtual void UnkFunc32();
            virtual void UnkFunc33();
            virtual void UnkFunc34();
            virtual void UnkFunc35();
            virtual void UnkFunc36() {}
            virtual void UnkFunc37() {}
            virtual void UnkFunc38();
            virtual void UnkFunc39();
            virtual void UnkFunc40();
            virtual void UnkFunc41();
            virtual void UnkFunc42();
            virtual void UnkFunc43();
            virtual void UnkFunc44();
            virtual void UnkFunc45();
            virtual void UnkFunc46();
        };
    }
}