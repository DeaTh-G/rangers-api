#pragma once

namespace hh::game {
    class GOCTinyFsm2 : public hh::game::GOComponent {
        enum Flags : char {
            RECEIVE_MESSAGES, // INITIALIZED? -- set when receiving activate goc event
            UNK2, // set in constructor
            HIERARCHICAL,
            TRANSITION_PENDING,
            UNK5,
        };

        void* targetObject;
        void* fsm[9];
        void* state1[4];
        void* pendingTransitionState[4];
        csl::ut::Bitset<Flags> flags;
        uint32_t transitionPhase;
        csl::ut::InplaceMoveArray<void*, 1> unk11;
        UNKNOWN(csl::ut::MoveArray<void*>);
        UNKNOWN(void*);
        
		virtual void Update() {

        }

        inline void DispatchFSM(void* e) {
            fsm->Dispatch(targetObject || pOwnerGameObject, e);
        }
    };
}