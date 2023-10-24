#pragma once

namespace hh::game {
    class InputListener {
	public:
		virtual ~InputListener();
        virtual void IL_UnkFunc1() {};
        virtual void IL_UnkFunc2() {};
    };

    class InputComponent : public fnd::ReferencedObject {
    public:
        enum class Flags : char {
            LISTENING = 0,
            ENABLED = 1,
        };
    private:
        // enum class ActionState : uint16_t {
        //     PRESSED
        // }

        template<typename T>
        struct InputMonitor {
            csl::ut::Bitset<Flags> flags; //this seems to be kept in sync with the inputcomponent's flags (see SetUnk5Flag1)
            uint8_t inputMapSettingsIndex;
            int16_t mappingId;
            uint8_t mappingUnk1;
            T state;
        };

        char internalPlayerInputIndex;
        char objectLayer;
        char priority;
        bool unk4; // GOCInput's unk103
    public:
        csl::ut::Bitset<Flags> flags;
    private:
        InputManager* inputManager_; // This is set in RegisterInputComponent and used in GOCInput's OnGOCEvent and in SetUnk5Flag1, but I don't know why this is a separate pointer.
        InputManager* inputManager;
        InternalPlayerInput* internalPlayerInput;
        csl::ut::VariableString objectName;
        csl::ut::InplaceMoveArray<InputListener*, 2> inputListeners;
    public:
        csl::ut::MoveArray<InputMonitor<uint16_t>> actionMonitors;
        csl::ut::MoveArray<InputMonitor<uint32_t>> axisMonitors;
        csl::ut::MoveArray<InputMonitor<csl::math::Vector4>> unkMonitors; // probably not a vector but it takes the same space and alignment

        struct Config {
            uint32_t internalPlayerInputIndex;
            uint32_t objectLayer;
            uint32_t priority;
            int actionMonitorCount;
            int axisMonitorCount;
            int unkMonitorCount;
            const char* objectName;
            bool unk7;
        };

        InputComponent(csl::fnd::IAllocator* pAllocator, const Config& config, InputManager& inputManager);
        static InputComponent* Instantiate(csl::fnd::IAllocator* pAllocator, const Config& config, InputManager& inputManager);

        void RegisterInputListener(InputListener& listener);
        void UnregisterInputListener(InputListener& listener);

        void SetListening(bool value);
        void SetActionEnabled(int actionMonitorId, bool value);

        void MonitorActionMapping(const char* actionMappingName, int actionMonitorId, int unused);
        void MonitorAxisMapping(const char* axisMappingName, int axisMonitorId);
    };
}