#pragma once

namespace csl::fnd {
    class alignas(8) TlsfHeapBase : public HeapBase {
        struct BlockHead {
            UNKNOWN(uint64_t);
            UNKNOWN(uint64_t);
            UNKNOWN(uint64_t);
            UNKNOWN(uint64_t);
            UNKNOWN(uint32_t);
            uint32_t unknown[25];
            void* unknown2[25][32];
        };

        void* bufferBegin;
        void* bufferEnd;
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint64_t);
        UNKNOWN(uint32_t);
        uint64_t block;
        bool initialized;
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