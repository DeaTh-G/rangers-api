#pragma once

namespace app::player
{
	class Player : public hh::game::GameObject
	{
	public:
		INSERT_PADDING(136);
		virtual void* GetClassId();
	};
}