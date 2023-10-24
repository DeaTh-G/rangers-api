#pragma once

namespace hh::fnd {
    csl::fnd::IAllocator** GetAllocatorSystem();
    csl::fnd::IAllocator* GetTempAllocator(csl::fnd::IAllocator** allocatorSystem);
}
