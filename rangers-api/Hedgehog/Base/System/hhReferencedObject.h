#pragma once

namespace hh::fnd
{
	class alignas(8) ReferencedObject : public BaseObject
	{
	public:
		bool isRefCounted{};
		uint32_t RefCount{};
	};

	class RefByHandleObject : public ReferencedObject
	{
	};
}