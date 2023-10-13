#pragma once

namespace SurfRide
{
	class BinaryData : public ReferencedObject {
		void* pData{};
	public:
		BinaryData(void* pData): pData(pData) {}

		void* GetSWIFData() {
			return pData == nullptr || *reinterpret_cast<uint32_t*>(pData) != 'FIWS' ? nullptr : pData;
		}

		// void IncrementReferenceCount()
		// {
		// 	RefCount++;
		// }

		// void DecrementReferenceCount()
		// {
		// 	RefCount--;
		// }

		// uint16_t GetReferenceCount()
		// {
		// 	return RefCount;
		// }

		// void DeleteData()
		// {

		// }

		// void Cleanup()
		// {
		// 	if (pData)
		// 		DeleteData();
		// }
	};
}