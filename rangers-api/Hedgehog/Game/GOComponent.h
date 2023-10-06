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
	
	class GOComponent : public fnd::RefByHandleObject
	{
	public:
		enum GOCEvent {
			DEACTIVATE = 0,
			ACTIVATE,
			UNK2,
			UNK3,
			UNK4,
			UNK5,
			OBJECT_LAYER_CHANGED,
		};

		struct Unk1 {
			int64_t unk39;
			int64_t unk40;
		};

		uint32_t flags;
		int32_t unk45;
		GameObject* pOwnerGameObject{};
		uint32_t unk47;
		char flags38; // seen 0, 1, 2
		uint16_t unk49;
		char unk50;
		uint32_t unk51;
		uint32_t unk52;
		GOComponentClass* pStaticClass{};
		Unk1 unknown43[3];

		GOComponent(csl::fnd::IAllocator* pAllocator);

		virtual void* GetClassId();
		virtual void Update() {}
		virtual void GetDebugInfoMaybe();
		virtual bool ProcessMessage(fnd::Message& msg) { return false; }
		virtual bool fUnk5();
		virtual void LoadReflection(const fnd::RflClass& rflClass) {}

		/*
		 * When event is OBJECT_LAYER_CHANGED, data contains previous layer id.
		 */
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) {}

		static GOComponent* Instantiate(GameObject& ownerGameObject, const GOComponentClass& componentClass);
	};
}