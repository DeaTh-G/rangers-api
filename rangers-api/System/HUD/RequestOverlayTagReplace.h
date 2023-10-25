#pragma once

namespace app::ui
{
	class RequestOverlayTagReplace
	{
		void* pUnk4{};
		void* pUnk5{};
		int64_t Unk6{ 0x80000000 };
		hh::fnd::ThreadSafeTlsfHeapAllocator* pAllocator{ hh::game::GameManager::GetSingleton()->pAllocator };
	};
}