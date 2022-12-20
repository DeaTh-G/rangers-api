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
		inline static void* ms_addrSetupCaptionInfo = sigScan("\x48\x89\x5C\x24\x10\x48\x89\x6C\x24\x18\x48\x89\x74\x24\x20\x57\x48\x83\xEC\x40\x48\x8B\x41\x08", "xxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x140753F10);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpSetupCaptionInfo, ms_addrSetupCaptionInfo, RequestOverlayCaption*, const char*, const char*, float);

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