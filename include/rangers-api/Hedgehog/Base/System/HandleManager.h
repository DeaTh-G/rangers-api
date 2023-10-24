#pragma once

namespace hh::fnd
{
	class HandleManager : public ReferencedObject {
        csl::ut::MoveArray<RefByHandleObject*> objects;
        void* begin;
        void* end;
        void* count;
        void* field_50;
        void* current;
        void* pAllocator2;
        void* field_68;
    public:
        HandleManager(csl::fnd::IAllocator* pAllocator, size_t size);
        static HandleManager* Instantiate(csl::fnd::IAllocator* pAllocator, size_t size);
    };
}
