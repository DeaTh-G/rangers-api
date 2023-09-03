#pragma once

namespace hh::fnd
{
	class alignas(8) BaseObject
	{
	protected:
		csl::fnd::IAllocator* pAllocator{};
	public:
		virtual ~BaseObject() = default;

		csl::fnd::IAllocator* GetAllocator() const
		{
			return pAllocator;
		}
	};
}