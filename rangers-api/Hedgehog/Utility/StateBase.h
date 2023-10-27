#pragma once

namespace hh::ut
{
	namespace internal
	{
		class StateImpl : public hh::fnd::ReferencedObject
		{
			// TODO (ĐeäTh): Map out the full class definition

		public:
			int StateID;
		};
	}

	template<typename T>
	class StateBase : public internal::StateImpl
	{
		// TODO (ĐeäTh): Map out the full class definition
	};
}