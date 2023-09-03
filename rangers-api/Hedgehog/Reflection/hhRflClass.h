#pragma once

namespace hh::fnd
{
	class RflClassMember;
	
	class RflClass : public RflEntity
	{
	protected:
		const RflClass* m_pParent{};
		uint32_t m_ClassSize{};
		const RflArray<RflClassEnum> m_pEnums{};
		const RflArray<RflClassMember> m_pMembers{};
		const RflCustomAttributes* m_pAttributes{};

	public:
		RflClass(const char* pName, 
			const RflClass* pParent,
			uint32_t objectSizeInBytes,
			const RflClassEnum* pDeclaredEnums,
			uint32_t declaredEnumsNum,
			const RflClassMember* pDeclaredMembers,
			uint32_t declaredMembersNum,
			const RflCustomAttributes* pAttributes) : RflEntity(pName)
		{
			m_pParent = pParent;
			m_ClassSize = objectSizeInBytes;
			m_pEnums = { pDeclaredEnums, declaredEnumsNum };
			m_pMembers = { pDeclaredMembers, declaredMembersNum };
			m_pAttributes = pAttributes;
		}

		[[nodiscard]] const RflClass* GetBaseType() const
		{
			return m_pParent;
		}

		[[nodiscard]] uint32_t GetSizeInBytes() const
		{
			return m_ClassSize;
		}
		
		[[nodiscard]] uint32_t GetNumMembers() const
		{
			uint32_t count = m_MemberCount;

			for (const RflClass* base = m_pParent; base != nullptr; base = base->m_pParent)
			{
				count += base->m_MemberCount;
			}
			
			return count;
		}

		[[nodiscard]] const RflClassMember* GetMember(uint32_t i) const
		{
			const uint32_t num = GetNumMembers();

			if (i > num)
			{
				return nullptr;
			}

			const RflClass* cls = this;
			int j = i - num;

			while(true)
			{
				j += cls->m_MemberCount;
				if (j >= 0)
					break;

				cls = cls->m_pParent;
				if (!cls)
					return cls->m_pMembers;
			}
			
			return &cls->m_pMembers[j];
		}

		[[nodiscard]] const RflClassMember* GetMemberByName(const char* name) const
		{
			for (uint32_t i = 0; i < GetNumMembers(); i++)
			{
				const RflClassMember* member = GetMember(i);
				if (member->GetName() == name || !strcmp(member->GetName(), name))
				{
					return member;
				}				
			}
			
			return nullptr;
		}

		[[nodiscard]] uint32_t GetDeclaredMemberIndexByName(const char* name) const
		{
			if (m_MemberCount <= 0)
				return -1;

			for (uint32_t i = 0; i < m_MemberCount; i++)
			{
				const auto* memberName = m_pMembers[i].GetName();
				if (memberName == name || !strcmp(memberName, name))
				{
					return i;
				}
			}
			
			return -1;
		}

		[[nodiscard]] const RflClassMember* GetDeclaredMemberByName(const char* name) const
		{
			const uint32_t i = GetDeclaredMemberIndexByName(name);

			if (i == static_cast<uint32_t>(-1))
				return nullptr;

			return &m_pMembers[i];
		}
		
		[[nodiscard]] const RflCustomAttribute* GetAttribute(const char* name) const
		{
			if (!m_pAttributes)
				return nullptr;

			return m_pAttributes->GetAttribute(name);
		}
	};
}