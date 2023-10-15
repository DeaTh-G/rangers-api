#pragma once

namespace hh::game {
    class InputListener {
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
    };

    class InputComponent : public fnd::ReferencedObject {
    private:
        enum class Flags : char {
            LISTENING = 0,
            ENABLED = 1,
        };

        template<typename T>
        struct InputMonitor {
            csl::ut::Bitset<Flags> flags; //this seems to be kept in sync with the inputcomponent's flags (see SetUnk5Flag1)
            uint8_t inputMapSettingsIndex;
            int16_t mappingId;
            uint8_t mappingUnk1;
            T unk6;
        };

        char unk1;
        char objectLayer;
        char unk3;
        bool unk4; // GOCInput's unk103
        csl::ut::Bitset<Flags> flags;
        InputManager* inputManager_; // This is set in RegisterInputComponent and used in GOCInput's OnGOCEvent and in SetUnk5Flag1, but I don't know why this is a separate pointer.
        InputManager* inputManager;
        void* unk7;
        csl::ut::VariableString objectName;
        csl::ut::InplaceMoveArray<InputListener*, 2> inputListeners;
        csl::ut::MoveArray<InputMonitor<uint16_t>> actionMonitors;
        csl::ut::MoveArray<InputMonitor<uint32_t>> axisMonitors;
        csl::ut::MoveArray<InputMonitor<csl::math::Vector4>> unkMonitors; // probably not a vector but it takes the same space and alignment
    public:
        struct Config {
            uint32_t unk1;
            uint32_t objectLayer;
            uint32_t unk3;
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