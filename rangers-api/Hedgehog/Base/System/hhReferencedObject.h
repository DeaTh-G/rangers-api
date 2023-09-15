#pragma once

namespace hh::fnd
{
	class alignas(8) ReferencedObject : public BaseObject
	{
	public:
		bool isRefCounted{};
		uint32_t RefCount{};

		ReferencedObject(bool isRefCounted) : isRefCounted(isRefCounted) {}
	};

	class RefByHandleObject : public ReferencedObject
	{
	};
}