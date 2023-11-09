#pragma once

namespace app::player {
    class StatePluginBase : public hh::fnd::ReferencedObject {
    public:
        StatePluginBase(csl::fnd::IAllocator* allocator) : hh::fnd::ReferencedObject{ allocator, true } {}
    };

    template<typename Ctx>
    class StatePlugin : public StatePluginBase {
    public:
        StatePlugin(csl::fnd::IAllocator* allocator) : StatePluginBase{ allocator } {}
    };

    
}
