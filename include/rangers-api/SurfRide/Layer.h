#pragma once

namespace SurfRide
{
	// class Layer;
	// class Transform;
	// class SRS_TRS_BASE;
	// class SRS_MOTION;
	// class SRS_TRACK;
	// class DrawInterface;
	// class SRS_CELL3D;
	// class TextureList;

	struct SRS_CASTNODE;

	// class Cast : public Base
	// {
	// public:
	// 	virtual Color GetLocalMaterialColor() const;
	// 	virtual Color GetGlobalMaterialColor() const;
	// 	virtual void SetLocalMaterialColor(const Color& in_rColor);
	// 	virtual Color GetLocalIlluminationColor() const;
	// 	virtual Color GetGlobalIlluminationColor() const;
	// 	virtual void SetLocalIlluminationColor(const Color& in_rColor);
	// 	virtual bool GetLocalDisplayFlag() const;
	// 	virtual bool GetGlobalDIsplayFlag() const;
	// 	virtual void SetLocalDisplayFlag(bool in_displayFlag);
	// 	virtual ~Cast() = default;
	// 	virtual void CalcMotion(float in_unk, float in_unk2, bool in_unk3, bool in_unk4, const SRS_MOTION* in_pMotion);
	// 	virtual void MakeCellData(bool in_unk, Transform* in_pTransform, void* in_pUnk2);
	// 	virtual void Update(float in_deltaTime, const Transform* in_pTransform, const Cast* in_pCast, Transform* in_pTransform2, void* in_pUnk);
	// 	virtual void UpdateParentsAndThisTransformRecursively();
	// 	virtual void UpdateParentsTransformRecursively();
	// 	virtual void UpdateThis(float in_deltaTime, const Transform* in_pTransform, const Cast* in_pCast, Transform* in_pTransform2, void* in_pUnk);
	// 	virtual void Draw(DrawInterface* in_pInterface, Transform* in_pTransform, void* in_pUnk);
	// 	virtual Transform* GetTransform();
	// 	virtual void CalcTrackTypeWidth(float in_unk, const SRS_TRACK* in_pTrack);
	// 	virtual void CalcTrackTypeHeight(float in_unk, const SRS_TRACK* in_pTrack);
	// 	virtual void CalcTrackTypeCropIndex0(float in_unk, const SRS_TRACK* in_pTrack);
	// 	virtual void CalcTrackTypeCropIndex1(float in_unk, const SRS_TRACK* in_pTrack);
	// 	virtual int GetCellCount() const;
	// 	virtual void InitializeTransformFromLayerBuffer(Transform* in_pTransform);
	// 	virtual void CopyTransformToLayerBuffer(Transform* in_pTransform, Transform* out_pTransform, bool in_unk);
	// 	virtual void CopyCellToLayerBuffer(void* in_pCell, void* out_pCell, uint in_unk);
	// 	virtual void* GetCell() const;
	// 	virtual void EntryStateCallBack(void (*)(const SRS_CELL3D& in_rCell, TextureList** in_ppTextureList));
	// 	virtual void DeleteStateCallBack();

	// 	INSERT_PADDING(4);
	// 	Transform* pTransform{};
	// 	SRS_TRS_BASE* pBinaryTransform{};
	// 	INSERT_PADDING(4); // ReferenceCount<Blur>;
	// 	INSERT_PADDING(4); // ReferenceCount<Reflect>;
	// 	INSERT_PADDING(4);
	// 	SRS_CASTNODE* pCastNode{};
	// 	int RefCount{};
	// 	Layer* pParentLayer{};
	// 	INSERT_PADDING(8);
	// 	ReferenceCount<Cast> rcUnk1{};
	// 	ReferenceCount<Cast> rcUnk2{};
	// 	ReferenceCount<Cast> rcUnk3{};
	// 	int Flags{};
	// 	ReferenceCount<BinaryData> rcBinaryData{};
	// 	INSERT_PADDING(1);
	// 	bool OwnsBinaryData{};
	// 	INSERT_PADDING(6);

	// 	void IncrementReferenceCount()
	// 	{
	// 		RefCount++;
	// 	}

	// 	void DecrementReferenceCount()
	// 	{
	// 		RefCount--;
	// 	}

	// 	int GetReferenceCount()
	// 	{
	// 		return RefCount;
	// 	}

	// 	void DeleteData()
	// 	{
	// 		SrFree(this);
	// 	}

	// 	bool Cleanup()
	// 	{
	// 		if (OwnsBinaryData)
	// 			DeleteData();
	// 	}
	// };

	// struct Unk {
	// 	csl::ut::MoveArray<void*> unk1;
	// };

	struct SRS_LAYER
	{
		const char* pName{};
		int ID{};
		int Flags{};
		int CastCount{};
		SRS_CASTNODE* pCasts{};
		void* pCells{};
		int AnimationCount{};
		SRS_ANIMATION* pAnimations{};
		int CurrentAnimationIndex{};
		void* pUserData{};
	};

	class Cast;
	class ReferenceCast;
	class Scene;
	class Layer : public ReferencedObject
	{
	public:
		struct Unk2 {
			csl::math::Vector4 translation;
			uint32_t rotationX;
			uint32_t rotationY;
			uint32_t rotationZ;
			csl::math::Vector4 scale;
			csl::ut::Color<uint8_t> materialColor;
			csl::ut::Color<uint8_t> illuminationColor;
			int32_t unk7;
			int32_t unk8;
			uint16_t unk9;
			uint32_t unk10[13];
			Layer* layer;
			uint64_t unk16;
			uint64_t unk17;
			csl::math::Matrix44 unk18;
			
			Unk2(Layer* layer);
		};

		csl::ut::MoveArray<void*> unk1;
		const SRS_LAYER* layerData;
		csl::ut::VariableString name;
		Scene* scene;
		ReferenceCast* referenceCast;
		csl::ut::MoveArray<Cast*> casts;
		csl::ut::MoveArray<void*> unk5;
		csl::ut::MoveArray<Cast*> animatingCasts;
		csl::ut::MoveArray<void*> unk7;
		csl::ut::MoveArray<void*> unk8;
		csl::ut::StringMap<Cast*> castsByName;
		uint32_t currentAnimationIndex;
		float currentFrame;
		float currentFrame2;
		float startFrame;
		float endFrame;
		float unk11a;
		float currentFrame3;
		uint32_t unk13;
		uint32_t flags;
		bool atAnimationStart;
		bool unk14b;
		bool isLooping;
		bool dontLoop;
		bool atAnimationEnd;
		bool playInReverse;
		bool unk16;
		uint32_t unk17;
		uint32_t unk18;
		uint32_t unk19;
		Unk2 unk20;

		Layer(const SRS_LAYER& layerData, Scene* scene);

		const char* GetName() const
		{
			return layerData->pName;
		}

		Cast* GetCast(const char* name);

		// void IncrementReferenceCount()
		// {
		// 	RefCount++;
		// }

		// void DecrementReferenceCount()
		// {
		// 	RefCount--;
		// }

		// int GetReferenceCount()
		// {
		// 	return RefCount;
		// }

		// void DeleteData()
		// {

		// }

		// void Cleanup()
		// {
		// 	if (OwnsBinaryData)
		// 		DeleteData();
		// }

		SRS_ANIMATION* GetCurrentAnimation()
		{
			if (layerData->pAnimations)
				layerData->pAnimations[currentAnimationIndex];

			return layerData->pAnimations;
		}

		void SetAnimation(int animationId);

		int GetAnimationID() const
		{
			return layerData->pAnimations[currentAnimationIndex].ID;
		}

		int GetAnimationID(const char* name) const
		{
			if (!layerData->AnimationCount)
				return -1;
		
			for (size_t i = 0; i < layerData->AnimationCount; i++)
			{
				if (strcmp(layerData->pAnimations[i].pName, name) == 0)
					return layerData->pAnimations[i].ID;
			}

			return -1;
		}

		void SetHideFlag(bool in_hide)
		{
			if (in_hide)
				flags |= 0x100;
			else
				flags &= ~0x100;
		}

		bool StartAnimation(int animationId, float initialFrame, bool playInReverse);
		bool StartAnimation(int animationId);
		void SetAnimationFrame(float frame);

	private:
		void StartCurrentAnimation();
		void InitializeAnimation(SRS_ANIMATION* animation);
		void UpdateAnimation(float timestep);
	};
}