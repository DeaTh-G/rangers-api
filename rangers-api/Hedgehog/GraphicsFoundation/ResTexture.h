#pragma once

namespace hh::gfnd {
    class ResTexture : public fnd::ManagedResource {
        hh::needle::Texture* texture;
        void* unk102[12];
        uint64_t unk103;
        uint64_t unk104;
        uint8_t unk105;
        uint32_t nameHash;
    public:
        ResTexture(csl::fnd::IAllocator* allocator);
        static ResTexture* Instantiate(csl::fnd::IAllocator* allocator);
        static const fnd::ResourceTypeInfo* GetTypeInfo();

        hh::needle::Texture* GetTexture() { return texture; }

        virtual void UnkFunc2(void* unkParam, uint64_t unkParam2) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc5() override;
    };
}
