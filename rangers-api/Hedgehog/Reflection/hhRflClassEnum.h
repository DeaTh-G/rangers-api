#pragma once

namespace hh::fnd
{
	class RflClassEnumMember
	{
	protected:
		const size_t m_Idx{};
		const char* m_pEnglishName{};
		const char* m_pJapaneseName{};
		const uint64_t m_Flags{};

	public:
		[[nodiscard]] const char* GetEnglishName() const
		{
			return m_pEnglishName;
		}

		[[nodiscard]] const char* GetJapaneseName() const
		{
			return m_pJapaneseName;
		}

		[[nodiscard]] size_t GetIndex() const
		{
			return m_Idx;
		}

		[[nodiscard]] size_t GetFlags() const
		{
			return m_Flags;
		}
	};
	
	class RflClassEnum : public RflEntity
	{
	protected:
		const RflArray<RflClassEnumMember> m_pValues{};

	public:
		const RflClassEnumMember* GetValues() const
		{
			return m_pValues;
		}

		size_t GetValueCount() const
		{
			return m_MemberCount;
		}

		bool GetNameOfValue(size_t value, const char** pp_name) const
		{
			if (m_MemberCount <= 0)
				return false;

			if (!pp_name)
				return false;
			
			for (size_t i = 0; i < m_MemberCount; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues[i];
				
				if (p_member->GetValue() == value)
				{
					*pp_name = p_member->GetName();
					return true;
				}
			}
			
			return false;
		}

		bool GetValueOfName(const char* name, size_t* p_value) const
		{
			if (m_MemberCount <= 0)
				return false;

			if (!p_value)
				return false;

			for (size_t i = 0; i < m_MemberCount; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues[i];

				if (p_member->GetName() == name || !strcmp(p_member->GetName(), name))
				{
					*p_value = p_member->GetValue();
					return true;
				}
			}

			return false;
		}
	};
}