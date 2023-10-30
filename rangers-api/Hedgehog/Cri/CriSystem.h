#pragma once

namespace hh::cri {
    class CriSystem : public fnd::BaseObject {
        fnd::ThreadSafeTlsfHeapAllocator hedgehogAllocator;
    public:
        static CriSystem instance;
    };
}
