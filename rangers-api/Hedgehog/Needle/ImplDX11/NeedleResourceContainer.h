#pragma once

// ASCII magic numbers to select parts of the datastructure
// Generic interface for the container
#define NEEDLE_RESOURCE_CONTAINER 0x544E43535231314Eui64 // 'TNCSR11N'

// Location of a boolean
#define NEEDS_STR                 0x525453534445454Eui64 // 'RTSSDEEN'

namespace hh::needle::ImplDX11 {
    struct SDupTypeSupport {};
    struct SQueryTypeOwn {};

    template<typename Type, typename Impl, size_t MyInterfaceId = NEEDLE_RESOURCE_CONTAINER, typename SQueryType = SQueryTypeOwn, typename SQuerySupport = SDupTypeSupport>
    class NeedleResourceContainer : public Type {
        void* unk201;
        void* unk202vftable;
        Impl implementation;
        bool needsStr; // probably the value (and type) here is based on the 2 last template params

    public:
        static constexpr size_t InterfaceId = MyInterfaceId;

        NeedleResourceContainer();
        void* QueryInterface(size_t magic) {
            switch (magic) {
                case MyInterfaceId: return this;
                case Type::InterfaceId: return this;
                case NEEDS_STR: return &needsStr;
                case Impl::InterfaceId: return &implementation;
                default: return implementation.QueryInterface(magic);
            }
        }

        template<typename T>
        inline T* QueryInterface(size_t magic) {
            return static_cast<T*>(QueryInterface(magic));
        }
    };
}
