#pragma once

namespace csl::ut
{
	class PointerMapOperation
	{
	protected:
		size_t m_Dummy;
		
	public:
		/*
		 * This uses MurmurHash3's avalanche mix finalizer for x64.
		 * I couldn't find any evidence for an actual hash function being used.
		 * Maybe they decided that pointers are random enough to be acceptably
		 * distributed after only applying an avalanche mixer.
		 */
		size_t hash(size_t k)
		{
			k ^= k >> 33;
			k *= 0xff51afd7ed558ccd;
			k ^= k >> 33;
			k *= 0xc4ceb9fe1a85ec53;
			k ^= k >> 33;

			return k;
		}

		bool compare(size_t key, size_t other)
		{
			return key == other;
		}
	};

	template<typename TKey, typename TValue>
	class PointerMap : public HashMap<PointerMapOperation>
	{
		size_t keyCast(TKey key) const
		{
			return (size_t)key;
		}

		size_t valueCast(TValue value) const
		{
			return (size_t)value;
		}
		
	public:
		class iterator
		{
			friend PointerMap;
			const PointerMap* m_pOwner;
			size_t m_CurIdx;

			iterator(const PointerMap* pOwner, size_t index) : m_pOwner(pOwner), m_CurIdx(index)
			{

			}

		public:
			friend bool operator==(const iterator& a, const iterator& b) { return a.m_CurIdx == b.m_CurIdx; }
			friend bool operator!=(const iterator& a, const iterator& b) { return a.m_CurIdx != b.m_CurIdx; }

			iterator& operator++() { m_CurIdx = m_pOwner->GetNext(m_CurIdx); return *this; }
			iterator operator++(int) { iterator tmp = *this; m_CurIdx = m_pOwner->GetNext(m_CurIdx); return tmp; }

			TKey key() const
			{
				return reinterpret_cast<TKey>(m_pOwner->GetKey(HashMap<PointerMapOperation>::iterator{ m_pOwner, m_CurIdx }));
			}

			TValue get() const
			{
				return reinterpret_cast<TValue>(m_pOwner->GetValue(HashMap<PointerMapOperation>::iterator{ m_pOwner, m_CurIdx }));
			}

			TValue& operator*() const
			{
				return *reinterpret_cast<TValue*>(m_pOwner->GetValuePtr(HashMap<PointerMapOperation>::iterator{ m_pOwner, m_CurIdx }));
			}

			TValue operator->() const
			{
				return get();
			}

			operator TValue() const
			{
				return get();
			}

			operator TValue& ()
			{
				return operator*();
			}
		};
		
		PointerMap(fnd::IAllocator* pAllocator) : HashMap<csl::ut::PointerMapOperation>(pAllocator)
		{
			
		}

		iterator begin() const
		{
			return iterator(this, GetBegin());
		}
		
		iterator end() const
		{
			return iterator(this, GetCapacity());
		}
		
		void insert(TKey key, TValue value)
		{
			Insert(keyCast(key), valueCast(value));
		}

		void erase(TKey key)
		{
			Erase(keyCast(key));
		}
		
		iterator find(const TKey key) const
		{
			auto result = Find(keyCast(key));
			return iterator(this, result.m_CurIdx);
		}
	};
}