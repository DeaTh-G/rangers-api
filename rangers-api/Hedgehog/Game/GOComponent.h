#pragma once

namespace hh::game
{
	class GameObject;

	class alignas(8) ComponentClass
	{
	public:
		const char* pName;
		void* pUnk1{};
		void* pUnk2{};
	};
	
	class GOComponent : public hh::fnd::RefByHandleObject
	{
	public:
		INSERT_PADDING(8);
		GameObject* pOwner{};
		INSERT_PADDING(24);
		ComponentClass* pStaticClass{};
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