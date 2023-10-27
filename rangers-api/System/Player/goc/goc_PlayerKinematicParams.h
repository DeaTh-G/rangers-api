#pragma once

namespace app::player
{
	class GOCPlayerKinematicParams : public hh::game::GOComponent
	{
	private:
		inline static const char* ms_pComponentName = "GOCPlayerKinematicParams";

	public:
		csl::math::Vector3 Position;
		csl::math::Quaternion Rotation;
		csl::math::Vector3 UnitVector;
		INSERT_PADDING(0x20);
		csl::math::Vector3 Velocity;
		INSERT_PADDING(0x4F0);

		static const char* GetComponentName()
		{
			return ms_pComponentName;
		}
	};
}