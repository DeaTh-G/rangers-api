#pragma once

namespace hh::gfx {
    class GOCVisual : public game::GOComponent {
        uint8_t unk101;
        uint8_t unk102;
    public:
        GOCVisual(csl::fnd::IAllocator* allocator);
		virtual void* GetClassId() override;
        virtual uint64_t UnkFunc1() = 0;
    };
}
