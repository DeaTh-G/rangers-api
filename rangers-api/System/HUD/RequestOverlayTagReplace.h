#pragma once

namespace app::ui
{
	class RequestOverlayTagReplace
	{
		void* m_pUnk1{};
		void* m_pUnk2{};
		int64_t m_Unk3{ 0x80000000 };
		hh::fnd::ThreadSafeTlsfHeapAllocator* m_pAllocator{ GameManager::GetSingleton()->pAllocator };
	};
}