#pragma once

namespace app::ui
{
	class RequestOverlayBegin;

	class UIOverlayService : public hh::game::GameService, hh::game::GameUpdateListener, app::fnd::AppResourceManagerListener
	{
	private:
		inline static const char* ms_pServiceName = "UIOverlayService";
		
		inline static FUNCTION_PTR(int, __fastcall, ms_fpCreateOverlayJob, 0x14093AFB0, UIOverlayService*, RequestOverlayBegin*);
		
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
