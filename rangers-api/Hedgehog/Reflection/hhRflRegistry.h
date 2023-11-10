#pragma once

namespace hh::fnd
{
	class RflRegistryBase : public BaseObject
	{
	protected:
		csl::ut::StringMap<const RflEntity*> m_Items{ GetAllocator() };

		const RflEntity* GetByName(const char* pName) const
		{
			return m_Items.GetValueOrFallback(pName, nullptr);
		}
		
		void Register(const RflEntity* pInfo)
		{
			m_Items.Insert(pInfo->GetName(), pInfo);
		}

		void RegisterList(const RflEntity** pInfoList)
		{
			size_t i = 0;
			while (pInfoList[i])
			{
				Register(pInfoList[i]);
				i++;
			}
		}

	public:
		RflRegistryBase(csl::fnd::IAllocator* pAllocator) : BaseObject{ pAllocator }
		{

		}
	};

	template<typename T>
	class RflRegistryTemplate : public RflRegistryBase {
	public:
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
			RegisterList(pInfoList);
		}

		inline const csl::ut::StringMap<const T*>& GetItems() const {
			const csl::ut::StringMap<const RflEntity*>& items = m_Items;

			return reinterpret_cast<const csl::ut::StringMap<const T*>&>(items);
		}
	};
}
