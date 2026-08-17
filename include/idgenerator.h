#pragma once

#include <vector>

/**
 * @brief Dedicated class for generating unique IDs with a pooling system.
 * 
 * Systems using this class are responsible for returning any freed IDs to the pool.
 */
class IDGenerator 
{
public:
	uint32_t generateID()
	{
		if (m_IDPool.empty())
		{
			return m_nextID++;
		}

		uint32_t newID = m_IDPool.back();
		m_IDPool.pop_back();
		return newID;
	}

	void returnID(uint32_t freedID) { m_IDPool.push_back(freedID); }

private:
	uint32_t m_nextID {0};
	std::vector<uint32_t> m_IDPool;
};