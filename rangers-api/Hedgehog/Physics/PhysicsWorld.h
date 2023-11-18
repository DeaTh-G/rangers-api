#pragma once

namespace hh::physics {
    class PhysicsWorldListener {
    public:
        virtual ~PhysicsWorldListener() = default;
        virtual void PWL_UnkFunc1() {}
        virtual void PWL_UnkFunc2() {}
        virtual void PWL_UnkFunc3() {}
        virtual void PWL_UnkFunc4() {}
        virtual void PWL_UnkFunc5() {}
        virtual void PWL_UnkFunc6() {}
    };

    // This class is mostly guessed from dtor and previous engine versions because it is obfuscated
    class PhysicsWorld : public game::GameService {
        uint64_t unk100;
        csl::ut::MoveArray<void*> unk101;
        csl::ut::MoveArray<void*> unk102;
        csl::ut::MoveArray<void*> unk103;
        csl::ut::MoveArray<void*> unk104;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
        csl::ut::MoveArray<void*> unk107;
        csl::ut::MoveArray<void*> unk108;
        csl::ut::MoveArray<void*> unk108b;
        EventQueue* eventQueue;
        uint32_t unk109;
        uint16_t unk110;
        bool unk111;
        uint64_t unk112;
        uint64_t unk113;
    public:
        PhysicsWorld(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t PerformRayCastClosest() = 0;
        virtual uint64_t PerformRayCastAllHits() = 0;
        virtual uint64_t UnkFunc9() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual uint64_t UnkFunc13() = 0;
    };
}
