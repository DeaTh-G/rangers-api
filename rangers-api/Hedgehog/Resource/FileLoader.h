#pragma once

namespace hh::fnd {
    class FileWin32 : public fnd::ReferencedObject {
        HANDLE fileHandle;
        uint32_t unk1;
    };

    class FileLoader : public csl::fnd::Singleton<FileLoader> {
    public:
        virtual void* GetFamilyID();
        virtual ~FileLoader();
        virtual uint64_t UnkFunc2(uint64_t unkParam);
        virtual uint64_t UnkFunc3(uint64_t unkParam);
        virtual uint64_t UnkFunc4(uint64_t unkParam);
        virtual uint64_t UnkFunc5(uint64_t unkParam);
        virtual uint64_t UnkFunc6(const char* unkParam);
        virtual uint64_t UnkFunc7(uint64_t unkParam);
        virtual uint64_t UnkFunc7a(uint64_t unkParam);
        virtual uint64_t OpenFile(const Uri& uri);
        virtual uint64_t UnkFunc8(const char* unkParam);
        virtual uint64_t UnkFunc12(uint64_t unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc13(const char* unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc14(uint64_t unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc15(const char* unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc16(uint64_t unkParam);
        virtual uint64_t UnkFunc17(uint64_t unkParam);
        virtual uint64_t UnkFunc18(uint64_t unkParam);
        virtual uint64_t UnkFunc19(const char* unkParam1);
        virtual uint64_t UnkFunc20(uint64_t unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc21(const char* unkParam1, const char* unkParam2);
        virtual uint64_t UnkFunc22(uint64_t unkParam);
        virtual uint64_t UnkFunc23(const char* unkParam1);
        virtual uint64_t UnkFunc24(uint64_t unkParam);
        virtual uint64_t UnkFunc25(const char* unkParam1);
        virtual uint64_t UnkFunc26(uint64_t unkParam);
        virtual uint64_t UnkFunc27(uint64_t unkParam);
    };
}
