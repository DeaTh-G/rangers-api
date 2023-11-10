#pragma once

namespace csl::ut
{
	class VariableString
	{
	protected:
		inline static const char* ms_Empty = "";
		
		char* m_pStr{};
		fnd::IAllocator* m_pAllocator{};

		inline bool isFree() const
		{
			return reinterpret_cast<size_t>(m_pStr) & 1;
		}
		
		void assign(fnd::IAllocator* pAllocator, const char* pStr, int size);
		
	public:
		VariableString(const char* pStr, csl::fnd::IAllocator* pAlloc)
		{
			assign(pAlloc, pStr, -1);
		}

		VariableString(const char* pStr, int size, csl::fnd::IAllocator* pAlloc)
		{
			assign(pAlloc, pStr, size);
		}

		VariableString(csl::fnd::IAllocator* pAlloc)
		{
			m_pAllocator = pAlloc;
		}

		VariableString(VariableString&& other);
		
		~VariableString()
		{
			m_pStr = nullptr;
			m_pAllocator = nullptr;
		}

		csl::fnd::IAllocator* GetAllocator() const
		{
			return m_pAllocator;
		}
		
		inline void Set(const char* pStr, int size, csl::fnd::IAllocator* pAlloc)
		{
			assign(pAlloc, pStr, size);
		}

		inline void Set(const char* pStr, int size)
		{
			assign(GetAllocator(), pStr, size);
		}

		inline void Set(const char* pStr)
		{
			assign(GetAllocator(), pStr, -1);
		}
		
		const char* c_str() const;
		// {
		// 	if (m_pStr)
		// 		return reinterpret_cast<const char*>(reinterpret_cast<size_t>(m_pStr) & ~1);

		// 	return ms_Empty;
		// }

		//char* c_str()
		//{
		//	if (m_pStr)
		//		return reinterpret_cast<char*>(reinterpret_cast<size_t>(m_pStr) & ~1);

		//	return m_pStr;
		//}

		bool Compare(const char* pStr) const
		{
			return strcmp(c_str(), pStr);
		}
		
		operator const char*() const
		{
			return c_str();
		}

		//operator char* ()
		//{
		//	return c_str();
		//}
		
		VariableString& operator=(const char* pStr)
		{
			Set(pStr);
			return *this;
		}

		friend bool operator==(const VariableString& lhs, const VariableString& rhs)
		{
			return lhs.Compare(rhs.c_str());
		}

		friend bool operator==(const VariableString& lhs, const char* rhs)
		{
			return lhs.Compare(rhs);
		}
	};
}