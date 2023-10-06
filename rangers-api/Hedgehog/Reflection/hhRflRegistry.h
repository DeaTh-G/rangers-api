#pragma once

namespace hh::fnd
{
	class RflRegistryBase : public BaseObject
	{
	protected:
		csl::ut::StringMap<RflEntity*> m_Items{ GetAllocator() };

	public:
		RflRegistryBase()
		{
			
		}

		const RflEntity* GetByName(const char* pName) const
		{
			auto result = m_Types[pName];
			if (result == m_Types.end())
				return nullptr;

			return result;
		}
		
		void Register(const RflEntity* pInfo)
		{
			m_Types.insert(pInfo->GetName(), pInfo);
		}

		void RegisterList(const RflEntity** pInfoList)
		{
			size_t i = 0;
			while (pInfoList[i])
			{
				RegisterTypeInfo(pInfoList[i]);
				i++;
			}
		}
	};

	template<typename T>
	class RflRegistryTemplate : public RflRegistryBase {
		inline const T* GetByName(const char* pName) const
		{
			return reinterpret_cast<const T*>(RflRegistryBase::GetByName(pName));
		}
		
		inline void Register(const T* pInfo)
		{
			Register(pInfo);
		}

		inline void RegisterList(const T** pInfoList)
		{
			RegisterList(pInfoList)
		}
	};
}
