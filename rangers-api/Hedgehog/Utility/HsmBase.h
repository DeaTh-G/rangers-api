#pragma once

namespace hh::ut
{
	namespace internal
	{
		class alignas(8) HsmImpl : public csl::ut::NonCopyable
		{
		public:
			INSERT_PADDING(4) { -1 };
			int CurrentStateIndex{};
			INSERT_PADDING(16);
			csl::ut::ObjectMoveArray<StateImpl*> pStates{};
			INSERT_PADDING(48);

			virtual ~HsmImpl() = default;
		};
	}

	class HsmBase : public internal::HsmImpl
	{

	};
}