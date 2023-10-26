#pragma once

namespace hh::fnd {
    class ResourceManager {
    public:
        class ResourceListener {
        public:
            virtual ~ResourceListener();
            virtual void RL_UnkFunc1(ManagedResource* resource) {}
            virtual void RL_UnkFunc2(void* unkParam1) {}
        };
    };
}
