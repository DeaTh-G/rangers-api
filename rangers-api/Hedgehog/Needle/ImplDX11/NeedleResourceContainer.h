#pragma once

// ASCII magic numbers to select parts of the datastructure
// Generic interface for the container
#define NEEDLE_RESOURCE_CONTAINER 0x544E43535231314Eui64 // 'TNCSR11N'

// Location of a boolean
#define NEEDLE_RESOURCE_NEEDS_STR                 0x525453534445454Eui64 // 'RTSSDEEN'

namespace hh::needle::ImplDX11 {
    struct SQueryTypeOwn {};
    struct SQueryTypeSelf {};
    struct SDupTypeSupport {
        void* unk201;
        void* unk202vftable;
    };
    struct SDupTypeNotSupport {};

    // Current assumption: QueryType chooses the handling of the QueryResource default branch, DupSupport handles something about the SetDuplicate function
    template<typename Type, typename Impl, size_t MyResourceId, typename SQueryType, typename SDupType>
    class NeedleResourceContainer : public Type {
        SDupType dupType;
        Impl implementation;
        bool needsStr; // probably the value (and type) here is based on the 2 last template params

    public:
        static constexpr size_t resourceId = MyResourceId;

        NeedleResourceContainer();
        
        virtual void* QueryResource(size_t id) override;
        //     switch (id) {
        //         case resourceId: return this;
        //         case Type::resourceId: return this;
        //         case NEEDS_STR: return &needsStr;
        //         default: return implementation.QueryResource(id);
        //     }
        // }
        
        virtual const void* QueryResource(size_t id) const override;
        //     switch (id) {
        //         case resourceId: return this;
        //         case Type::resourceId: return this;
        //         case NEEDS_STR: return &needsStr;
        //         default: return implementation.QueryResource(id);
        //     }
        // }
    };
}
