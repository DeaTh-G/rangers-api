#pragma once

namespace app::player
{
	class GOCPlayerVisual;

	class alignas(8) PlayerVisual : public hh::fnd::ReferencedObject
	{
	public:
		hh::game::GameObject* pOwner{};
		GOCPlayerVisual* pVisualGoc{};
		INSERT_PADDING(16) {};
		INSERT_PADDING(2) {};

		virtual size_t GetNameHash() const = 0;
		// 7 more virtual functions 
	};
}