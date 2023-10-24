#pragma once

#include <cstdlib>

extern "C" void RangersAPI_SetBaseAddress(void* address);
extern "C" void* RangersAPI_GetAddress(void* address);

namespace rangersapi::bootstrap {
	inline void SetBaseAddress(void* address) {
		RangersAPI_SetBaseAddress(address);
	}

	//namespace internal {
	//	struct mem_ptr {
	//		void* address;
	//		int adj;
	//		int vadj;
	//		int vindex;
	//	};

	//	// Normally we can't convert member function pointers to void* because member function pointers
	//	// of MI classes can be larger than a size_t, keeping things like the offset of the inner object.
	//	// This union will force a conversion for the purposes of shifting the address, and reinstate
	//	// the extra information.
	//	// 
	//	// This thing currently assumes MSVC ABI.
	//	template<typename T>
	//	union unsafe_convert_ptr {
	//		T typed;
	//		mem_ptr untyped;
	//	};
	//}

	//template<typename T>
	//T GetAddress(T target) {
	//	internal::unsafe_convert_ptr<T> in_addr{};
	//	internal::unsafe_convert_ptr<T> out_addr{};

	//	in_addr.typed = target;
	//	out_addr.untyped = in_addr.untyped;
	//	out_addr.untyped.address = RangersAPI_GetAddress(in_addr.untyped.address);

	//	return out_addr.typed;
	//}

	template<typename T>
	T GetAddress(T target) {
		void* r = RangersAPI_GetAddress((void*&)target);
		return (T&)r;
	}
}
