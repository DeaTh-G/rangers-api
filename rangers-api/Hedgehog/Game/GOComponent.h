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

		void* unk43;
		uint32_t flags;
		int32_t unk45;
		GameObject* pOwnerGameObject{};
		uint32_t unk47;
		char flags38; // seen 0, 1, 2
		uint16_t unk49;
		char unk50;
		void* unk51;
		GOComponentClass* pStaticClass{};
		Unk1 unknown43[3];

		GOComponent(csl::fnd::IAllocator* pAllocator);
		
		virtual void GetFamilyId() = 0;
		virtual void Update() = 0;
		virtual void GetDebugInfoMaybe() = 0;
		virtual void ProcessMessage(fnd::Message& msg) = 0;
		virtual void fUnk5() = 0;
		virtual void LoadReflection(const fnd::RflClass& rflClass) = 0;

		/*
		 * When event is OBJECT_LAYER_CHANGED, data contains previous layer id.
		 */
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) = 0;

		static GOComponent* Instantiate(GameObject& ownerGameObject, const GOComponentClass& componentClass);
	};
}