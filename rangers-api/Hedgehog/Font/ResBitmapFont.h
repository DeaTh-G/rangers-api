#pragma once

namespace hh::font {
    struct BFNT_CHUNK {
    };
    struct BFNT_ROOT {
        char magic[4];
        uint32_t unk1;
        char count;
        uint64_t unk2;
        BFNT_CHUNK** chunkPointerss;
    };
    class ResBitmapFont : public fnd::ManagedResource {
        BFNT_ROOT* binaryData;
    public:
        virtual void UnkFunc2(void* unkParam);
        virtual void UnkFunc3();
        virtual void UnkFunc4();
    };
}
