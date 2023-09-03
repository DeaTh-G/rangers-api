#pragma once

namespace hh::fnd
{
	class RflEntity
	{
	protected:
		const char* m_pName{};
    public:
        const char* GetName() const
		{
			return m_pName;
		}
    };
}
