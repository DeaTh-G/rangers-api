#pragma once

namespace SurfRide
{
	// struct SRS_LAYER;
	// class Layer;

	struct SRS_SCENE
	{
		const char* pName{};
		int ID{};
		int Flags{};
		int LayerCount{};
		SRS_LAYER* pLayers{};
		short CameraCount;
		short CurrentCameraIndex{};
		SRS_CAMERA* pCameras{};
		int BackgroundColor{};
		csl::math::Vector2 Resolution{};
		void* pUserData{};
	};

	class Project;
	class Scene : public ReferencedObject
	{
		SRS_SCENE* sceneData;
		Project* project;
		Camera camera;
		csl::ut::MoveArray<Layer*> layers;
		uint32_t unk1;
		uint32_t flags;

	public:
		Scene(const SRS_SCENE& sceneData, Project* project);

		Layer* GetLayer(const char* layers);
		// SRS_SCENE* pBinaryScene{};
		// int RefCount{};
		// Camera Camera{};
		// int CurrentCameraIndex{};
		// Project* pOwner{};
		// ReferenceCount<Layer>* prcLayers{};
		// int LayerCount{};
		// int Priority{};
		// Math::Vector2 Resolution{ 1.0f, 1.0f };
		// INSERT_PADDING(4) {};
		// bool IsMultiResolutionProcess{};
		// int Flags{};
		// ReferenceCount<BinaryData> rcBinaryData{};
		// bool OwnsBinaryData{};
		// INSERT_PADDING(7);

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

		// const char* GetName()
		// {
		// 	return pBinaryScene->pName;
		// }

		// const ReferenceCount<Layer> GetLayer(const char* in_pLayerName) const;
	};
}