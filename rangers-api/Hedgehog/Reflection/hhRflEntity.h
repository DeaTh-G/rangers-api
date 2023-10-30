#pragma once

namespace hh::fnd
{
	class RflEntity
	{
	protected:
    public:
		const char* m_pName{};
		RflEntity(const char* name) : m_pName{ name } {}

        const char* GetName() const
		{
			return m_pName;
		}
    };
}
