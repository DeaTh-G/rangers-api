#pragma once

namespace hh::fnd
{
	class HandleBase
	{
	protected:
		uint32_t m_Handle;

		void Set(const RefByHandleObject* pObj)
		{
			if (pObj)
			{
				m_Handle = pObj->m_Handle;
			}
		}
		
	public:
		HandleBase()
		{
			
		}
		
		HandleBase(const RefByHandleObject* pObj)
		{
			Set(pObj);
		}

        // TODO: fix
		RefByHandleObject* Get(void* handleManager) const
		{
			return null;
		}

		bool operator==(const RefByHandleObject* pObj)
		{
			return m_Handle == pObj->m_Handle;
		}

		bool operator!=(const RefByHandleObject* pObj)
		{
			return !operator==(pObj);
		}

		HandleBase& operator=(const RefByHandleObject* pObj)
		{
			Set(pObj);
			return *this;
		}

		HandleBase& operator=(const HandleBase& hObj)
		{
			m_Handle = hObj.m_Handle;
			return *this;
		}
	};

	template<class T>
	class Handle : public HandleBase
	{
	public:
		Handle()
		{
			
		}

		Handle(const T* pObj) : HandleBase(pObj)
		{
			
		}

		T* Get(void* handleManager) const
		{
			return reinterpret_cast<T*>(HandleBase::Get());
		}

		Handle<T>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		Handle<T>& operator=(const Handle<T>& hObj)
		{
			m_Handle = hObj.m_Handle;
			return *this;
		}

		operator T*() const
		{
			return Get();
		}

		T* operator->() const
		{
			return Get();
		}
	};
}
