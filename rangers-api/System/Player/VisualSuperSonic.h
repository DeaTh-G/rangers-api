#pragma once

namespace app::player
{
	class VisualSuperSonic : public VisualHuman
	{
	private:
		inline static void* ms_addrChangeToSuperSonic2 = sigScan("\x40\x56\x48\x83\xEC\x30\x80\xB9\x00\x00\x00\x00\x00\x48\x8B\xF1\x0F\x85\x00\x00\x00\x00", "xxxxxxxx?????xxxxx????", (void*)0x1409DD9F0);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpChangeToSuperSonic2, ms_addrChangeToSuperSonic2, VisualSuperSonic*);

	public:
		inline static const char* ms_pName = "VisualSuperSonic";

	public:
		INSERT_PADDING(32) {};

		void ChangeToSuperSonic2()
		{
			ms_fpChangeToSuperSonic2(this);
		}
	};
}