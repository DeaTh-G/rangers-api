#pragma once

namespace hh::game
{
	class GOCInput : hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCInput";

	public:
		enum EButtonState : uint32_t
		{
			EButtonState_Inactive = 0,
			EButtonState_Press    = 0x13000000,
			EButtonState_Release  = 0x4000000,
			EButtonState_Hold     = 0x1000000
		};

		INSERT_PADDING(0x124);
		EButtonState A{};
		INSERT_PADDING(0x04);
		EButtonState Y{};
		INSERT_PADDING(0x14);
		EButtonState RightTrigger{};
		INSERT_PADDING(0x0C);
		EButtonState LeftStick{};
		INSERT_PADDING(0x04);
		EButtonState LeftBumper{};
		INSERT_PADDING(0x04);
		EButtonState RightBumper{};
		INSERT_PADDING(0x04);
		EButtonState B{};
		INSERT_PADDING(0x0C);
		EButtonState X{};
		INSERT_PADDING(0x0C);
		EButtonState RightStick{};
		INSERT_PADDING(0x04);
		EButtonState LeftTrigger{};
		INSERT_PADDING(0x10);
		float LeftStickX{};
		INSERT_PADDING(0x14);
		float LeftStickY{};
		INSERT_PADDING(0x14);
		float RightStickX{};
		INSERT_PADDING(0x14);
		float RightStickY{};

		static bool IsPressed(EButtonState in_buttonState)
		{
			return (in_buttonState & EButtonState_Press) == EButtonState_Press;
		}

		static bool IsReleased(EButtonState in_buttonState)
		{
			return (in_buttonState & EButtonState_Release) == EButtonState_Release;
		}

		static bool IsDown(EButtonState in_buttonState)
		{
			return (in_buttonState & EButtonState_Hold) == EButtonState_Hold;
		}

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}
	};
}