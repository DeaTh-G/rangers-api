#pragma once
#pragma push_macro("RegisterClass")
#undef RegisterClass

namespace hh::fnd
{
	class RflClassNameRegistry : public RflRegistryTemplate<RflClass>, csl::fnd::SingletonPointer<RflClassNameRegistry>
	{
	};
}

// DEFINE_SINGLETONPTR(hh::fnd::RflClassNameRegistry, ASLR(0x00FD430C));
#pragma pop_macro("RegisterClass")