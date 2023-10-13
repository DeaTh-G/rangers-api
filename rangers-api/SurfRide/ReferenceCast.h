#pragma once

namespace SurfRide
{
	struct SRS_REFERENCECAST
	{
		SRS_LAYER* m_pLayer{};
		int m_Flags{};
		int m_AnimationID{};
		int m_AnimationFrame{};
		int m_Unk2{};
	};

	class ReferenceCast : public Cast {
	public:
		const SRS_REFERENCECAST* referenceCastData;
		Layer* layer;
		uint32_t animationId;
		bool isFlag2Set;
		uint32_t flags;

		ReferenceCast(const SRS_CASTNODE& castData, void* unkParam, Layer* layer);
	};
}
