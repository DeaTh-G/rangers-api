#pragma once

namespace hh::game {
    class InputListener {
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
    };

    class GOCInput : public GOComponent, public InputListener {
        bool unk101a;
        bool unk101b;
        bool unk101c;
        bool unk101d;
        bool unk102a;
        bool unk102b;
        bool unk103;
        bool unk104;
        void* unk105;

        static GOCInput* Instantiate(csl::fnd::IAllocator* pAllocator);
    public:
        struct alignas(8) Config {
            bool unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk3b;
            uint32_t unk4;
            uint32_t unk4b;
            uint32_t unk5;
            uint32_t unk5b;
            uint64_t unk6;
            uint64_t unk7;
        };

        void Initialize(const Config& config);
		virtual void* GetClassId();
		virtual bool fUnk5() { return true; }
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data);
    };
}
