#pragma once

namespace hh::fnd {
    class FilePathResolver : public ReferencedObject, public ResourceNameResolver {
        const char* extension;
    public:
        FilePathResolver(csl::fnd::IAllocator* allocator, const char* extension);
        virtual const char* RNR_UnkFunc1(const char* name) override;
        virtual char* RNR_UnkFunc2(const char *a2, uint64_t a3, char *a4, size_t Count) override;
    };
}
