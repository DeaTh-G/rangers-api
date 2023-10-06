#pragma once

namespace hh::fnd {
    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
        csl::ut::VariableString unk1;
        csl::ut::VariableString unk2;
        csl::ut::VariableString unk3;
        void* unk4;
        void* unk5;
        void* unk6;
        void* unk7;
        void* unk8;
        void* unk9;

    public:
        ManagedResource();

    }
}