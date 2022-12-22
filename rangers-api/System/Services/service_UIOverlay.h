#pragma once

namespace app::ui
{
	class RequestOverlayBegin;

	class UIOverlayService : public hh::game::GameService, hh::game::GameUpdateListener, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "UIOverlayService";
		
		inline static void* ms_addrCreateOverlayJob = sigScan("\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x4C\x8B\xF1\x48\x8B\xEA", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x14093AFB0);
		inline static FUNCTION_PTR(int, __fastcall, ms_fpCreateOverlayJob, ms_addrCreateOverlayJob, UIOverlayService*, RequestOverlayBegin*);
		
		INSERT_PADDING(88);
		INSERT_PADDING(32); // some struct, +0x18 value = pAllocator
	
	public:
		int JobCount;

	private:
		INSERT_PADDING(96);

	public:
		int CreateOverlayJob(RequestOverlayBegin* in_pOverlay)
		{
			return ms_fpCreateOverlayJob(this, in_pOverlay);
		}

		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}
