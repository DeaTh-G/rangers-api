#pragma once

namespace hh::fnd
{
	class RflClass;

	class RflCustomAttribute : public RflEntity
	{
	protected:
		const void* m_pData{};
		RflClass* m_pType{};

	public:
		[[nodiscard]] const void* GetData() const
		{
			return m_pData;
		}

		[[nodiscard]] const RflClass* GetType() const
		{
			return m_pType;
		}
	};
	
	class RflCustomAttributes : public RflArray<RflCustomAttribute>
	{
	public:
		[[nodiscard]] const RflCustomAttribute* GetAttribute(const char* name) const
		{
			for (size_t i = 0; i < m_Count; i++)
			{
				const auto* attribute = &m_pAttributes[i];

				if (attribute->GetName() == name || !strcmp(attribute->GetName(), name))
				{
					return attribute;
				}
			}
			
			return nullptr;
		}
	};
}