#pragma once

namespace hh::game {
    enum TinyFsmSignal : char {
        TiFSM_SIGNAL_LEAVE = -4,
        TiFSM_SIGNAL_ENTER = -3,
        TiFSM_SIGNAL_INIT = -2,
        TiFSM_SIGNAL_SUPER = -1,
        TiFSM_SIGNAL_UPDATE = 0,
        TiFSM_SIGNAL_UPDATE_PHASE_0 = 4,
        TiFSM_SIGNAL_UPDATE_PHASE_1 = 5,
        TiFSM_SIGNAL_UPDATE_PHASE_2 = 6,
        TiFSM_SIGNAL_MESSAGE = 7,
        TiFSM_SIGNAL_USER = 100,
    }

    enum TinyFsmStateType : char {
        TFSM_STATE_TYPE_0 = 0
        TFSM_STATE_TYPE_DELEGATE = 0
        TFSM_STATE_TYPE_TOP = 0
        TFSM_STATE_TYPE_3 = 0
        TFSM_STATE_TYPE_4 = 0
    }

    class TinyFsmEvent {
        TinyFsmSignal signal;
    }

    template<typename T>
    class TinyFsmState<T> {
        typedef TinyFsmState<T>* (T::*MemberPtr)(TinyFsmState &result, TinyFsmEvent *inputEvent);
    }

    template<typename T, typename TEvent = TiFsmBasicEvent<T>>
	class TTinyFsm
	{
	public:
		typedef TEvent Event_t;
		typedef TTinyFsmState<T, TEvent> State_t;

	private:
		State_t m_Src;
		State_t m_Cur;
        bool hierarchical;

		inline static State_t GetTopState()
		{
            
        }

		void InitCurrentState(T* obj)
		{
			while (m_Cur.Init(obj).IsType3())
			{
				m_Cur.Enter(obj);
			}
		}

		void InitFSM(T* obj)
		{
			if constexpr (Hierarchical)
			{
				csl::ut::InplaceMoveArray<State_t, 5> stateStack{ fnd::GetTempAllocator() };
				State_t state = m_Cur;

				while (state != FSM_TOP())
				{
					stateStack.push_back(state);
					state = state.Super(obj);
				}

                // Enter states until we reach our target state.
                for(auto stateIt = stateStack.end(); stateIt != stateStack.begin(); ) {
                    stateIt--;
					stateIt->Enter(obj);
				}
			}
			else
			{
				m_Cur.Enter(obj);
			}

			InitCurrentState(obj);
		}

		void ShutdownFSM(T* obj)
		{
			if constexpr (Hierarchical)
			{
				State_t state = m_Cur;
				while (state != FSM_TOP())
				{
					state.Leave(obj);
					state = state.Super(obj);
				}

				m_Cur.Clear();
				m_Src.Clear();
			}
			else
			{
				Leave(m_Cur);
				m_Cur.Clear();
			}
		}

        void Transition(T* obj, const State_t& in_state) {
            if (m_Cur == in_state)
                return;

            if (m_Src.IsType2()) {
                m_Src = m_Cur;
            }

            if (hierarchical) {
				for (State_t state = m_Cur; state != m_Src; state = state.Super(obj))
				{
					state.Leave(obj);
				}

				if (m_Src == in_state)
				{
					Leave(m_Src);
			        m_Cur = in_state;
					Enter(in_state);
				}
                else
                {
					csl::ut::InplaceMoveArray<State_t, 5> oldStates{ fnd::GetTempAllocator() };
					csl::ut::InplaceMoveArray<State_t, 5> newStates{ fnd::GetTempAllocator() };
					State_t oldState = m_Cur;
					State_t newState = in_state;

                    // Run up the hierarchy and collect all superstates of both the old and the new state.
					while (oldState != FSM_TOP())
					{
						oldStates.push_back(oldState);
						oldState = oldState.Super(obj);
					}

					while (newState != FSM_TOP())
					{
						newStates.push_back(newState);
						newState = newState.Super(obj);
					}

                    // Compare both lists starting from the topmost state and find the deepest superstate that's common to both states.
                    auto oldStateIt = oldStates.end();
                    auto newStateIt = newStates.end();

                    while (oldStateIt != oldStates.begin() && newStateIt != newStates.begin());
                    {
                        oldStateIt--;
                        newStateIt--;

                        if (*oldStateIt != *newStateIt)
                            break;
                    }
                    
                    // Leave states until we reach the nearest common state.
					for (auto i = oldStates.begin(); i <= oldStateIt; i++)
					{
						i->Leave(obj);
					}

                    // Enter states until we reach our target state.
					for(; newStateIt >= newStates.begin(); newStateIt--)
					{
                        m_Cur = *newStateIt;
						newStateIt->Enter(obj);
					}
                }
            }
			else
			{
				m_Cur.Leave(obj);
			    m_Cur = in_state;
				in_state.Enter(obj);
			}

			InitCurrentState(obj);
        }

    public:
		void Dispatch(T* obj, const TEvent& in_event)
		{
			if (hierarchical)
			{
				m_Src = m_Cur;

				while (!m_Src.IsType2() && !m_Src.IsType3())
				{
					State_t state = m_Src.Trigger(obj, in_event);
					if (state.IsType3() || state.IsType0()) break;

					m_Src = m_Src.Super(obj);
				}
			}
			else
			{
				m_Cur.Trigger(obj, in_event);
			}
		}
    };

	template<typename T, typename TEvent>
	class TTinyFsmState
	{
	public:
        typedef TTinyFsmState (T::*Delegate_t)(const TEvent& e);
		typedef TTinyFsmState (*Callback_t)(T* obj, TTinyFsmState prevState, const TEvent& e);

        struct alignas(8) Unk1 {
            uint64_t fst;
            uint64_t snd;
        }

        union Data_t {
            Delegate_t delegate;
            Unk1 unk;
        };
        Data_t data;
        Callback_t callback;
        TinyFsmStateType type;

		TTinyFsmState() = default;
        TTinyFsmState(TinyFsmStateType type) : type(type) {}
        TTinyFsmState(TinyFsmStateType type, Callback_t callback) : type(type), callback(callback) {}

		void Clear()
		{
			m_Delegate = nullptr;
		}

		State_t Trigger(T* obj, const TEvent& in_event)
		{
			return callback(obj, this, in_event);
		}

		State_t Super(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_SUPER });
		}

		State_t Init(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_INIT });
		}

		State_t Enter(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_ENTER });
		}

		State_t Leave(T* obj)
		{
			return Trigger(obj, { TiFSM_SIGNAL_LEAVE });
		}

        bool IsType0()
        {
            return type == 0;
        }
        
        bool IsType2()
        {
            return type == 2;
        }

        bool IsType3()
        {
            return type == 3;
        }

        bool IsNotType0()
        {
            return !IsType0();
        }

        TTinyFsmState& operator=(const TTinyFsmState& other) {
            callback = other.callback;
            type = other.type;

            if (other.signal == 1)
                data.delegate = other.data.delegate;
            else
            {
                data.unk.fst = 0;
                data.unk.snd = 0;
            }
        }

		bool operator==(const TTinyFsmState& other) const
		{
            return IsNotType0() && other.IsNotType0() && type == other.type && unk.fst == other.unk.fst;
		}

		bool operator!=(const TTinyFsmState& other) const
		{
			return !(this == other);
		}

        static TTinyFsmState CreateType0() {
            return { 0 };
        }

        static TTinyFsmState CreateUnhandled() {
            return { 2 };
        }

        static TTinyFsmState CreateHandled() {
            return { 3 };
        }

        static TTinyFsmState CreateType4() {
            return {
                4,
                [](T* obj, TTinyFsmState prevState, const TEvent& e) {
                    if (e.signal == TiFSM_SIGNAL_LEAVE || e.signal == TiFSM_SIGNAL_ENTER || e.signal == TiFSM_SIGNAL_UPDATE)
                        return CreateHandled();
                    else
                        return CreateUnhandled();
                }
            };
        }
	};
}