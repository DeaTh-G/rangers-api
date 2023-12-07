#pragma once

namespace csl::fnd {
    class alignas(8) TlsfHeapBase : public HeapBase {
        struct BlockHead {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            uint32_t unk5;
            uint32_t unk6[25];
            void* unk7[25][32];
        };

        void* bufferBegin;
        void* bufferEnd;
    public:
        uint32_t liveAllocations;
        uint32_t totalAllocations;
        uint64_t unk102;
        uint64_t unk103;
        uint32_t blockCount;
        uint64_t block;
        bool initialized;
        TlsfHeapBase(const char* name);
    };

    template<typename TLock>
    class alignas(8) TlsfHeapTemplate : public TlsfHeapBase {
        TLock m_Lock;

		void* Alloc(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = TlsfHeapBase::Alloc(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void* AllocBottom(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = TlsfHeapBase::AllocBottom(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void Free(void* in_pMemory) override
		{
			m_Lock.Lock();
			TlsfHeapBase::Free(in_pMemory);
			m_Lock.Unlock();
		}
    };
}