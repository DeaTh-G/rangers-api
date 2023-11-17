#pragma once

#define VIEWER_CONTEXT_CLASS_DECLARATION(ClassName) private:\
		static const hh::dbg::ViewerContextClass* instance;\
        ClassName(csl::fnd::IAllocator* allocator);\
		static ClassName* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::dbg::ViewerContextClass* GetClass();

namespace hh::dbg {
    class ViewerContext;

    struct ViewerContextClass {
        const char* name;
        ViewerContext* (*instantiator)(csl::fnd::IAllocator* allocator);
    };

    class ViewerContext : public fnd::ReferencedObject {
        uint64_t unk1;
        const ViewerContextClass* viewerContextClass;
    public:
        ViewerContext(csl::fnd::IAllocator* allocator);

        inline static ViewerContext* Create(csl::fnd::IAllocator* allocator, const ViewerContextClass* viewerContextClass) {
            ViewerContext* ret = viewerContextClass->instantiator(allocator);
            ret->viewerContextClass = viewerContextClass;
            return ret;
        }

        template<typename T>
        static T* Create(csl::fnd::IAllocator* allocator) {
            return static_cast<T*>(Create(allocator, T::GetClass()));
        }
    };
}
