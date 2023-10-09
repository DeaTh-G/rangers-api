#pragma once

namespace hh::fnd
{
	inline Messenger* HandleManagerBase::GetObjectByHandle(uint32_t in_handle)
	{
		size_t id = in_handle & 0xFFFF;

		if ((in_handle & 0xFFFF0000) == 0 || !Handles[id].pMessenger || Handles[id].pMessenger->Handle != in_handle)
			return { nullptr };

		return Handles[id].pMessenger;
	}

	template<typename T>
	inline T* HandleManagerBase::GetObjectByHandle(uint32_t in_handle)
	{
		return static_cast<T*>(GetObjectByHandle(in_handle));
	}
}