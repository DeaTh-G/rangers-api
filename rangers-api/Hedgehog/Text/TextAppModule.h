#pragma once

namespace hh::text {
    class TextAppModule
        : public fw::AppModule
        , public fnd::ResourceManager::ResourceListener
        , public fnd::ReloaderListener
        , public font::FontContainerListener
    {
        csl::ut::VariableString defaultLocaleId;
        uint32_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        csl::ut::MoveArray<void*> unk106;
        TextLanguageDataCollection* textLanguageDataCollection;
        TagReplaceableCollection* tagReplaceableCollection;

        virtual void RL_UnkFunc1(fnd::ManagedResource* resource) override;
        virtual void RL_UnkFunc2(void* unkParam1) override;
        virtual void FCL_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2, uint64_t unkParam3) override;

        TextAppModule(csl::fnd::IAllocator* pAllocator);

        static TextAppModule* Instantiate(csl::fnd::IAllocator*);
    public:
        static const ConverseData* Translate(const char* tag, int localeIdx);
        const ConverseData* GetTranslation(const char* tag, int localeIdx);
    };
}
