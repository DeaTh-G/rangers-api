#pragma once

namespace hh::gfx {
    class GOCVisual : public game::GOComponent {
    public:
        enum class Flag {
            VISIBLE,
        };
    private:
        csl::ut::Bitset<Flag> flags;
        uint8_t unk102;
    public:
        GOCVisual(csl::fnd::IAllocator* allocator);
		virtual void* GetClassId() override;
        virtual void OnGOCVisualEvent(int unkParam1, unsigned int unkParam2, void* unkParam3) = 0;
    };
}
