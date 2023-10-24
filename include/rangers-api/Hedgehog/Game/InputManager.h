#pragma once

namespace hh::game {
    class InputComponent;
    class InternalPlayerInput : public fnd::ReferencedObject {
        uint32_t index;
        int32_t unk1;
        csl::ut::MoveArray<hid::InputMap*> inputMaps; // same length as InputManager's unk1
        csl::ut::MoveArray<InputComponent*> inputComponents;
        uint32_t maxMappingUnk1PlusOneOverAllInputMaps;
    public:
        void CreateInputMap(uint32_t index, hid::InputMapSettings* settings);
    };

    class InputManager : public GameService, public GamePauseListener, public GameStepListener {
        csl::ut::MoveArray<hid::InputMapSettings*> inputMapSettings;
        csl::ut::MoveArray<InputComponent*> inputComponents;
        csl::ut::MoveArray<InternalPlayerInput*> internalPlayerInputs;
        csl::ut::InplaceMoveArray<void*, 1> unk4; // Something being done with this in RegisterInputComponent
        char activeInternalPlayerInputs; // bitmask
        int32_t unk6;
    public:
        InputManager(csl::fnd::IAllocator* pAllocator);
        static InputManager* Instantiate(csl::fnd::IAllocator* pAllocator);
        void RegisterInputComponent(InputComponent& inputComponent);
        void UnregisterInputComponent(InputComponent& inputComponent);
        void CreateInputMaps(hid::InputMapSettings* settings);
    };
}