#pragma once

namespace app
{
    class ScriptSequence;
}

namespace app
{
	class ScriptSequenceManager : public hh::game::GameService, hh::game::GameStepListener, app::save::SaveManagerListener
	{
    private:
		inline static const char* ms_pServiceName = "ScriptSequenceManager";

    public:
        class CallbackData
        {
            INSERT_PADDING(8);

        public:
            const char* pName;
            void* pFunction;
        };

    public:
        csl::ut::MoveArray<ScriptSequence*> ScriptSequences;
        INSERT_PADDING(96);
        LPCRITICAL_SECTION pCriticalSection;
        INSERT_PADDING(32);
        csl::ut::MoveArray<CallbackData> CallbackFunctions;
        INSERT_PADDING(8);
        void* pRflScript;
        INSERT_PADDING(8);
        void* pRflTalkEventCameraPreset;
        
		static const char* GetServiceName()
		{
			return ms_pServiceName;
		}
	};
}