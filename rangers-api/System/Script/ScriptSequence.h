#pragma once

namespace app
{
	class ScriptSequence;
}

template <void (app::ScriptSequence::*callback)(lua_State*)>
void RegisterCallback(lua_State* in_pThis)
{
	lua_getglobal(in_pThis, "instance");
	auto* pSequence = reinterpret_cast<app::ScriptSequence*>(lua_touserdata(in_pThis, -1));
	lua_settop(in_pThis, -2);
	(pSequence->*callback)(in_pThis);
}

namespace app
{
	namespace game
	{
		class Script : public hh::fnd::ReferencedObject
		{
		public:
			struct LuaWrapper
			{

			public:
				lua_State* pLuaState{};
				char Unk1{};
				void* pUnk2{};
				hh::fnd::ThreadSafeTlsfHeapAllocator* pAllocator{};

			public:
				template <void (app::ScriptSequence::* callback)(lua_State*)>
				void RegisterLuaCallback()
				{
					const char* rightBrace = strchr(__FUNCSIG__, '}');
					if (!rightBrace)
						return;

					char truncatedSig[sizeof(__FUNCSIG__)]{};
					strncpy_s(truncatedSig, __FUNCSIG__, rightBrace - __FUNCSIG__);

					const char* lastColon = strrchr(truncatedSig, ':');
					if (!lastColon)
						return;
					
					// lastColon at this point still contains the colon and the two characters preceeding the right brace
					// at the end of the function name. To account for this we reduce the character array's size by two
					// and store the name from the index 1 to skip the colon at the start.
					char* functionName = new char[strlen(lastColon) - 2];
					snprintf(functionName, strlen(lastColon) - 2, &lastColon[1]);
					
					lua_register(pLuaState, functionName, (lua_CFunction)RegisterCallback<callback>);
				}

				template <void (app::ScriptSequence::* callback)(lua_State*)>
				void RegisterLuaCallback(const char* in_pFunctionName)
				{
					lua_register(pLuaState, in_pFunctionName, (lua_CFunction)RegisterCallback<callback>);
				}
			};
			
		private:
			LuaWrapper m_Wrapper{};

			INSERT_PADDING(160);

		public:
			LuaWrapper* GetLuaWrapper() const
			{
				return (LuaWrapper*)&m_Wrapper;
			}
		};
	}

	class ScriptSequenceManager : public hh::game::GameService, hh::game::GameStepListener, app::save::SaveManagerListener
	{
		INSERT_PADDING(232);
	};

	class ScriptSequence : public hh::fnd::Messenger, hh::game::GameStepListener
	{
	private:
		inline static void* ms_addrPlayLipAnimation = sigScan("\x40\x55\x56\x41\x55\x48\x8D\xAC\x24\x00\xFF\xFF\xFF", "xxxxxxxxxxxxx", (void*)0x14087E860);
		inline static FUNCTION_PTR(void, __fastcall, ms_fpPlayLipAnimation, ms_addrPlayLipAnimation, ScriptSequence*, const char*);
		
	public:
		ScriptSequenceManager* pManager;
		void* pUnk3{};
		game::Script* pScripts[5]{};
		INSERT_PADDING(4);
		char ScriptName[64]{};
		INSERT_PADDING(12);
		int OverlayType{};
		INSERT_PADDING(4);
		int OverlayJobCount;
		INSERT_PADDING(376);

		GameDocument* GetDocument()
		{
			return pManager->pDocument;
		}
		
		void SetCaptionType(int jobCount)
		{
			OverlayType = 4;
			OverlayJobCount = jobCount;
		}

		void PlayLipAnimation(const char* in_pCaptionName)
		{
			ms_fpPlayLipAnimation(this, in_pCaptionName);
		}
	};
}