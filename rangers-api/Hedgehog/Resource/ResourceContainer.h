#pragma once

namespace hh::fnd {
    class ResourceContainer : public ReferencedObject {
    public:
        virtual void* GetFamilyID();
        virtual ManagedResource* GetResourceByName(const char* name) const = 0;
        virtual int GetNumResources() const = 0;
        virtual void UnkFunc1() = 0;
        virtual ManagedResource* GetResourceByIndex(int index) const = 0;
    };
}
