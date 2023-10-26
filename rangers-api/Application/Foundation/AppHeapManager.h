#pragma once

namespace app::fnd {
    class AppHeapManager {
    public:
        static csl::fnd::IAllocator* GetResidentAllocator();
    };
}
