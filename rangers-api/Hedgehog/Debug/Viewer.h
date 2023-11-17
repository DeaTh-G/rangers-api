#pragma once

#define VIEWER_CLASS_DECLARATION(ClassName) private:\
        ClassName(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::dbg::ViewerClass* instance;\
		static ClassName* Create(csl::fnd::IAllocator* allocator);

namespace hh::dbg {
    class Viewer : public fnd::ReferencedObject {
        bool unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
        void* someDebuggerThing;
    public:
        Viewer(csl::fnd::IAllocator* allocator);

        virtual int64_t UnkFunc1();
        virtual int64_t UnkFunc2() {}
        virtual int64_t UnkFunc3() {}
        virtual int64_t UnkFunc4() {}
        virtual int64_t UnkFunc5();

        ViewerContext* GetViewerContext(ViewerContextClass* viewerContextClass);

        template<typename T>
        T* GetViewerContext() {
            return static_cast<T*>(GetViewerContext(T::GetClass()));
        }
    };
    
    class ViewerClass {
        const char* name;
        Viewer* (*instantiator)(csl::fnd::IAllocator* allocator);
    };
}
