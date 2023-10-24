#pragma once

namespace hh::fnd
{
	class HandleBase
	{
	protected:
		uint32_t handle;

		void Set(const RefByHandleObject* pObj)
		{
			if (pObj)
			{
				handle = pObj->handle;
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
			return nullptr;
		}

		bool operator==(const RefByHandleObject* pObj)
		{
			return handle == pObj->handle;
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
			handle = hObj.handle;
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
			handle = hObj.handle;
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
