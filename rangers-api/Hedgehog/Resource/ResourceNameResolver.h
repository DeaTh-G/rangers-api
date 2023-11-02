#pragma once

namespace hh::fnd {
    class ResourceNameResolver {
    public:
        virtual ~ResourceNameResolver();
        virtual const char* RNR_UnkFunc1(const char* name);
        virtual char* RNR_UnkFunc2(const char *a2, uint64_t a3, char *a4, size_t Count);
    };
}
