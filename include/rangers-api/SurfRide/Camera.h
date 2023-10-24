#pragma once

namespace SurfRide
{
	struct SRS_CAMERA
	{
		const char* pName{};
		int ID{};
		csl::math::Vector3 Position{};
		csl::math::Vector3 Target{};
		int Flags{};
		int Fov;
		float NearPlane{};
		float FarPlane{};
		uint64_t unk;
	};

	class Camera
	{
	public:
		SRS_CAMERA camera;
		csl::math::Matrix44 viewMatrix;
		csl::math::Matrix44 projectionMatrix;

		Camera(const SRS_CAMERA& camera, float resolutionX, float resolutionY);
	};
}
