#pragma once

namespace app::ui
{
	struct CaptionInfo
	{
		void* m_Unk4{};
		void* m_Unk5{};
		int64_t m_Unk6{ 0x80000000 };
		hh::fnd::ThreadSafeTlsfHeapAllocator* m_pAllocator{ GameDocument::GetSingleton()->pAllocator };
	};

	class RequestOverlayCaption : public RequestOverlayBegin, public RequestOverlayTagReplace, public CaptionInfo
	{
	private:
		inline static FUNCTION_PTR(void, __fastcall, ms_fpSetupCaptionInfo, 0x140753F10, RequestOverlayCaption*, const char*, const char*, float);

	public:
		int Unk9{};
		char Type{};
		char Unk10{};
		char Unk11{ 10 };
		char Unk12{};

		RequestOverlayCaption()
		{
			pAllocator = GameDocument::GetSingleton()->pAllocator;
		}

		void SetupCaptionInfo(const char* in_pTextName, const char* in_pCueName, float in_Unk2)
		{
			ms_fpSetupCaptionInfo(this, in_pTextName, in_pCueName, in_Unk2);
		}
	};
}