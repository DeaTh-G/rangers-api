#pragma once

namespace hh::fw
{
	class Application : public fnd::ReferencedObject, public KeyEventHandler, public MouseEventHandler
	{
	public:
		INSERT_PADDING(72);
	};
}