#pragma once

namespace app::player
{
	class Sonic;
}

namespace hh::game
{
	class GOComponent;
	class GameObject;
	class GOComponentClass
	{
	public:
		const char* pName;
		void* inheritanceChain{};
		GOComponentClass* parent{};
		const char* dynamicName;
		size_t size;
        GOComponent* (*Instantiate)(csl::fnd::IAllocator* pAllocator);
		void* unk1;
		void* unk2;
	};
	
	class GOComponent : public hh::fnd::RefByHandleObject
	{
	public:
		INSERT_PADDING(16);
		GameObject* pOwnerGameObject{};
		INSERT_PADDING(24);
		GOComponentClass* pStaticClass{};
		INSERT_PADDING(48);
		
		virtual void fUnk1() = 0;
		virtual void fUnk2() = 0;
		virtual void fUnk3() = 0;
		virtual void fUnk4() = 0;
		virtual void fUnk5() = 0;
		virtual void fUnk6() = 0;
		virtual void fUnk7() = 0;
		virtual void fUnk8() = 0;
	};
}