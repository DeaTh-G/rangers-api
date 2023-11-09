#pragma once

namespace hh::needle {
    class NeedleRefcountResource : public NeedleRefcountObject {
    public:
        virtual void* QueryResource(size_t id) = 0;
        virtual const void* QueryResource(size_t id) const = 0;
        virtual void SetDebugObjectName(char const* name) {}
        virtual uint32_t SetDuplicate() { return 0; }
        virtual bool UnkFunc7() { return false; }

        template<typename T>
        inline T* QueryResource(size_t id) {
            return static_cast<T*>(QueryResource(id));
        }

        template<typename T>
        inline T* QueryResource(size_t id) const {
            return static_cast<T*>(QueryResource(id));
        }
    };
}
