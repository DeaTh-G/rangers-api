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

	// template<typename T>
	// class RflCustomAttributeTemplate : public RflCustomAttribute {
	// public:
	// 	typedef T UnderlyingType;
	
	// public:
	// 	inline const T* GetData() const
	// 	{
	// 		return reinterpret_cast<T*>(RflCustomAttribute::GetData());
	// 	}
	// }
	
	class RflCustomAttributes : public RflArray<RflCustomAttribute>
	{
	public:
		[[nodiscard]] const RflCustomAttribute* GetAttribute(const char* name) const
		{
			for (size_t i = 0; i < count; i++)
			{
				const auto* attribute = &items[i];

				if (attribute->GetName() == name || !strcmp(attribute->GetName(), name))
				{
					return attribute;
				}
			}
			
			return nullptr;
		}
	};
}