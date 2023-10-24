#include <stdint.h>

#define EXPORTING_TYPES

typedef struct _RTL_CRITICAL_SECTION {
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;        // from the thread's ClientId->UniqueThread
    void* LockSemaphore;
    void* SpinCount;        // force size on 64-bit systems when packed
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;

long InterlockedExchangeAdd(long volatile* Addend, long value);

void* sigScan(const char* signature, const char* mask, size_t sigSize, void* memory, const size_t memorySize);
void* sigScan(const char* signature, const char* mask, void* hint);
int strcmp(const char* x, const char* y);

namespace csl::math 
{
	class Vector2 { public: float x; float y; };
	class alignas(16) Vector3 { public: float x; float y; float z; };
	class alignas(16) Vector4 { public: float x; float y; float z; float w; };
	class Angle3 : Vector3 {};
	class alignas(16) Quaternion  {
	public:
		float x; float y; float z; float w;
		void SetRotationBetweenVectors(const Vector4& a, const Vector4& b, const Vector4& fallback);
	};
	class alignas(16) Matrix44 {
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	public:
		static Matrix44 CreateViewMatrix(Vector3 position, Vector3 up, Vector3 target);
		static Matrix44 CreateOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
		static Matrix44 CreatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
	};
	class alignas(16) Matrix34 : Matrix44 {};

	class Segment3
	{
	public:
		Vector3 m_Start{};
		Vector3 m_End{};
	};

	class Capsule
	{
	public:
		Segment3 m_Segment{};
		float m_Radius{};
	};
	
	class Aabb
	{
	public:
		Vector3 m_Min{};
		Vector3 m_Max{};
	};

	class Transform
	{
	public:
		Vector3 m_Position;
		Quaternion m_Rotation;
		Vector3 m_Scale;
		bool m_IsDirty;
	};

	class CalculatedTransform
	{
	public:
		Matrix34 m_Mtx;
		Vector3 m_Scale;
		size_t m_Flags;
	};

	template<typename T>
	inline static const T& Clamp(const T& value, const T& min, const T& max)
	{
		if (value < min)
			return min;
		
		if (value > max)
			return max;
		
		return value;
	}

	template<typename T>
	inline static const T& Max(const T& value, const T& max)
	{
		if (value > max)
			return value;

		return max;
	}

	template<typename T>
	inline static const T& Min(const T& value, const T& min)
	{
		if (value < min)
			return value;

		return min;
	}
	
	class Constants
	{
	public:
		inline static const Vector2 Vector2Zero{ 0, 0 };
		inline static const Vector3 Vector3Zero{ 0, 0, 0 };
		inline static const Quaternion QuaternionIdentity{ 0, 0, 0, 1 };
	};
}

#include "include/rangers-api/rangers-api.h"

// template class csl::ut::MoveArray<csl::fnd::IAllocator*>;
template class csl::fnd::Delegate<void ()>;
template class csl::fnd::Delegate<void (hh::ui::UIListViewElement*, bool)>;
template class csl::fnd::Delegate<void (hh::ui::UIListViewElement*, hh::ui::ListViewEventArg&)>;
template class csl::fnd::Delegate<void (hh::ui::GOCSprite*)>;
template class csl::fnd::Delegate<void (hh::ui::GOCUIComposition*)>;
template class csl::ut::Pair<app::ui::UIMusicSelect*, void (app::ui::UIMusicSelect::*)(hh::ui::UIListViewElement*, hh::ui::ListViewEventArg&)>;
template class hh::game::InputComponent::InputMonitor<uint16_t>;
template class hh::game::InputComponent::InputMonitor<uint32_t>;
template class hh::game::InputComponent::InputMonitor<csl::math::Vector4>;
template class csl::ut::InplaceMoveArray<const char*, 32>;
template class csl::ut::Pair<SurfRide::ReferenceCast*, hh::ui::UIListViewElement::Cursor*>;
template class hh::fnd::Reference<hh::ui::UIListViewElement::Cursor>;
template class hh::fnd::Reference<hh::ui::UIElement>;
template class hh::fnd::Reference<hh::ui::UIElementBase>;
