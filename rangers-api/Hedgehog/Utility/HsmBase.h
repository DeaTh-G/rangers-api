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
			StateImpl* pState{};
			INSERT_PADDING(40);

			virtual ~HsmImpl() = default;

		public:
			StateImpl* getState(int in_index) const
			{
				return pStates[in_index];
			}

			int getCurrentStateID() const
			{
				if (CurrentStateIndex)
					return getState(CurrentStateIndex - 1)->StateID;

				return -1;
			}
		};
	}

	class HsmBase : public internal::HsmImpl
	{

	};
}