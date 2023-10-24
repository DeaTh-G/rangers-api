#pragma once

namespace SurfRide
{
	enum SRE_CURVE_TYPE : uint16_t
	{
		eCurveType_TranslationX,
		eCurveType_TranslationY,
		eCurveType_TranslationZ,
		eCurveType_RotationX,
		eCurveType_RotationY,
		eCurveType_RotationZ,
		eCurveType_ScaleX,
		eCurveType_ScaleY,
		eCurveType_ScaleZ,
		eCurveType_MaterialColor,
		eCurveType_Display,
		eCurveType_Width,
		eCurveType_Height,
		eCurveType_VertexColorTopLeft,
		eCurveType_VertexColorTopRight,
		eCurveType_VertexColorBottomLeft,
		eCurveType_VertexColorBottomRight,
		eCurveType_CropIndex0,
		eCurveType_CropIndex1,
		eCurveType_Unknown,
		eCurveType_IlluminationColor,
		eCurveType_MaterialColorR,
		eCurveType_MaterialColorG,
		eCurveType_MaterialColorB,
		eCurveType_MaterialColorA,
		eCurveType_VertexColorTopLeftR,
		eCurveType_VertexColorTopLeftG,
		eCurveType_VertexColorTopLeftB,
		eCurveType_VertexColorTopLeftA,
		eCurveType_VertexColorTopRightR,
		eCurveType_VertexColorTopRightG,
		eCurveType_VertexColorTopRightB,
		eCurveType_VertexColorTopRightA,
		eCurveType_VertexColorBottomLeftR,
		eCurveType_VertexColorBottomLeftG,
		eCurveType_VertexColorBottomLeftB,
		eCurveType_VertexColorBottomLeftA,
		eCurveType_VertexColorBottomRightR,
		eCurveType_VertexColorBottomRightG,
		eCurveType_VertexColorBottomRightB,
		eCurveType_VertexColorBottomRightA,
		eCurveType_IlluminationColorR,
		eCurveType_IlluminationColorG,
		eCurveType_IlluminationColorB,
		eCurveType_IlluminationColorA,
	};

	// TODO: parser doesn't understand unions yet
	// union SRU_FRAME_TYPE
	// {
	// 	int Int;
	// 	bool Boolean;
	// 	char Character;
	// 	float Float;
	// 	csl::ut::Color<uint8_t> Color;
	// };

	struct SRS_KEYFRAME
	{
		uint32_t Frame{};
		// SRU_FRAME_TYPE Value{};
		uint32_t Value{};
	};

	struct SRS_TRACK
	{
		SRE_CURVE_TYPE TrackType{};
		uint16_t KeyCount{};
		uint32_t Flags{};
		uint32_t FirstFrame{};
		uint32_t LastFrame{};
		SRS_KEYFRAME* pKeyFrame{};
	};

	struct SRS_MOTION
	{
		uint16_t CastId{};
		uint16_t TrackCount{};
		SRS_TRACK* pTracks{};
	};

	struct SRS_ANIMATION
	{
		const char* pName{};
		uint32_t ID{};
		uint32_t LinkCount{};
		uint32_t FrameCount{};
		SRS_MOTION* pLinks{};
		void* pUserData{};
		bool IsLooping{};
	};
}