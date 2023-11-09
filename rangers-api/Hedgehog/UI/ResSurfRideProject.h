#pragma once

namespace hh::ui {
    class ResSurfRideProject : public fnd::ManagedResource {
        csl::ut::MoveArray<void*> unk101;
        void* unk102;
        uint16_t unk103;
    public:
        static const fnd::ResourceTypeInfo* GetTypeInfo();
        static ResSurfRideProject* Load(const char* name);
    };
}
