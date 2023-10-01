#pragma once

namespace hh::game {
    class ObjInfo;

    class ObjInfoClass {
    public:
        const char *pName;
        ObjInfo* (*Instantiate)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
        void* unk5;
        void* resourceLoader;
        void* unk7;
        void* unk8;
    public:
        ObjInfo(csl::fnd::IAllocator* pAllocator);
        virtual void Unk1() {}
        virtual void Unk2() {}
        virtual void Unk3() {}
        virtual const char* GetName() { return ""; }
        virtual void Unk5() {}
    };
}
