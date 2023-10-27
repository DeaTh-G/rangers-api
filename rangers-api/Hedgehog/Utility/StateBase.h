#pragma once

namespace hh::ut
{
	namespace internal
	{
		class StateImpl : public hh::fnd::ReferencedObject
		{
		public:
			int StateID;
			INSERT_PADDING(20);
		};

		class StateDescImpl
		{
		public:
			typedef StateImpl* (*StateCreate_t)(csl::fnd::IAllocator*);

			const char* pName{};
			StateCreate_t fpCreate{};
			int Unk1{ -1 };
		};
	}

	template<typename T>
	class StateBase : public internal::StateImpl
	{
		typedef bool (T::*ProcessMessage_t)(hh::fnd::Message*, bool);

	public:
		csl::ut::ObjectMoveArray<ProcessMessage_t*> Unknown1{};
		csl::ut::ObjectMoveArray<void*> Unknown2{};
		void* pUnknown3;
		INSERT_PADDING(56) {};
	};

	class StateDesc : public internal::StateDescImpl
	{
		virtual ~StateDesc() = default;
	};
}