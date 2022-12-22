#pragma once

namespace app::player
{
	class BlackboardContent : public hh::fnd::ReferencedObject
	{
		INSERT_PADDING(8);

		virtual size_t GetNameHash();
	};

	class Blackboard : public hh::fnd::ReferencedObject
	{
	private:
		inline static void* ms_addrGetBlackboardContent = sigScan("\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x20\x48\x8B\x79\x18\x8B\xEA", "xxxxxxxxxxxxxxxxxxxxxxxxxx", (void*)0x1407798C0);
		inline static FUNCTION_PTR(BlackboardContent*, __fastcall, ms_fpGetBlackboardContent, ms_addrGetBlackboardContent, Blackboard*, size_t);

	public:
		csl::ut::MoveArray<BlackboardContent> Blackboards;

		template <typename T>
		T* GetBlackboardContent()
		{
			return reinterpret_cast<T*>(ms_fpGetBlackboardContent(this, T::GetHashedName()));
		}
	};
}