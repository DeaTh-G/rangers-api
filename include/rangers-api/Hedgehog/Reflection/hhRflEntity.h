#pragma once

namespace hh::fnd
{
	class RflEntity
	{
	protected:
		const char* m_pName{};
    public:
		RflEntity(const char* name) : m_pName{ name } {}

        const char* GetName() const
		{
			return m_pName;
		}
    };
}
