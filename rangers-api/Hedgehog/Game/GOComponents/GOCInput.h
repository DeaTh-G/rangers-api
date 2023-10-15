#pragma once

namespace hh::game {
    class GOCInput : public GOComponent, public InputListener {
        bool startListeningOnInitialization;
        // These are copied to InputComponent on GOC event activate
        uint8_t inputComponentConfigUnk1;
        uint8_t inputComponentConfigUnk3;
        uint8_t inputComponentConfigActionMonitorCount;
        uint8_t inputComponentConfigAxisMonitorCount;
        uint8_t inputComponentConfigUnknownMonitorCount;
        bool inputComponentConfigUnk7;
        bool unk104;
        hh::game::InputComponent* inputComponent;

    public:
        struct alignas(8) Config {
            bool unk1;
            uint32_t inputComponentConfigUnk1;
            uint32_t inputComponentConfigUnk3;
            uint32_t inputComponentConfigActionMonitorCount;
            uint32_t inputComponentConfigAxisMonitorCount;
            uint32_t inputComponentConfigUnknownMonitorCount;
            bool inputComponentConfigUnk7;
        };

        GOCInput(csl::fnd::IAllocator* pAllocator);
        static GOCInput* Instantiate(csl::fnd::IAllocator* pAllocator);
        static GOComponentClass* GetClass();
        void Initialize(const Config& config);
		virtual void* GetClassId();
		virtual bool fUnk5() { return true; }
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data);
        
        inline InputComponent* GetInputComponent() const {
            return inputComponent;
        }
    };
}
