#pragma once

namespace hh::ui {
    class UIManager : public game::GameService, public game::GameStepListener {
    public:
        // struct UIActions {
        //     const char* up;
        //     const char* down;
        //     const char* left;
        //     const char* right;
        //     const char* decide;
        //     const char* cancel;
        //     const char* pageUp;
        //     const char* pageDown;
        // };

        struct Config {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            UITextInterface* textInterface;
            uint32_t unk6;
            const char* uiActions[8];
            const char* unk7[1]; // unk118 in the service
        public:
            Config();
        };

    private:
        uint32_t unk101;
        uint32_t unk101a;
        uint32_t unk102;
        uint32_t unk103;
        UITextInterface* textInterface;
        uint32_t unk105;
        const char* uiActions[8];
        csl::ut::MoveArray<void*> unk114;
        csl::ut::MoveArray<TextObjectUpdater*> textObjectUpdaters;
        csl::ut::VariableString unk116[8];
        uint64_t unk117;
        uint64_t unk118;
        int unk119;
        uint32_t unk120;

    public:
        void Initialize(const Config& config);

    private:
        static hh::game::GameServiceClass gameServiceClass;
        static hh::game::GameService* Instantiate(csl::fnd::IAllocator* pAllocator);
        
    public:
        static hh::game::GameServiceClass* GetClass();
        void RegisterTextObjectUpdater(TextObjectUpdater* textObjectUpdater);
        void UnregisterTextObjectUpdater(TextObjectUpdater* textObjectUpdater);
    };
}
