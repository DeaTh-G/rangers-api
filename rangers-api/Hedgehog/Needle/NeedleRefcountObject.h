#pragma once

namespace hh::needle {
    class NeedleRefcountObject : public NeedleObject {
        uint32_t refCount;
    protected:
        virtual void ReleasePostDestroyInternal();
        virtual void GetDependRefcountObject();
        virtual ~NeedleRefcountObject();
    };
}
