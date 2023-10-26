#pragma once

namespace SurfRide {
    class CastListener {
    public:
        virtual ~CastListener();
        virtual void* GetClassId();
        virtual int64_t Unk1();
        virtual int64_t Unk2();
        virtual int64_t Unk3();
        virtual int64_t Unk4();
        virtual int64_t Unk5();
        virtual int64_t Unk6();
        virtual int64_t Unk7();
        virtual int64_t Unk8();
    };

	struct SRS_CASTNODE
	{
		const char* m_pName{};
		int m_ID{};
		int m_Flags{};
		void* m_pData{};
		short m_ChildIndex{};
		short m_SiblingIndex{};
		SRS_USERDATA* m_pUserData{};
	};

    class Cast : public ReferencedObject {
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
        uint64_t unk5;
        const SRS_CASTNODE* castData;
        Layer* layer;
        Cast* parentCast;
        csl::ut::MoveArray<SurfRide::Cast*> children;
        SRS_MOTION* motion;
        uint32_t flags;
        bool unk8;
        bool unk8a; // set in constructor to a flag of the layer
        uint16_t unk9;
        uint16_t unk9a;
        uint64_t unk10;
        uint64_t unk11;
        uint64_t unk11a;

        // This is actually an as of yet unknown subobject (sub_141128CF0)
        csl::ut::MoveArray<void*> unk12;

        Cast* self;
        bool unk14;
    public:

        Cast(const SRS_CASTNODE& castData, Cast* parentCast, Layer* layer);
        UserData GetUserData();
        void SetFlag1000(bool enabled);

        virtual void UnkFunc1();
        virtual void UnkFunc2();
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual uint32_t UnkFunc8() { return 0; }
        virtual void UnkFunc9() {}
        virtual uint32_t UnkFunc10() { return 0; }
        virtual void UnkFunc11();
        virtual void UnkFunc12();
    };
}
