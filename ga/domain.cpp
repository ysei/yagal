#include "domain.h"
#include "solution.h"

Domain::Domain() : m_bits(0)
{

}

Domain::~Domain()
{

}

void Domain::addFloat()
{

}

void Domain::addInt()
{
    m_bits += sizeof(int) * 8;
    m_valueOffsets.push_back(m_bits);
}

float Domain::getFloat(int index, const Solution &solution) const
{
    return 0.0f;
}

int Domain::getInt(int index, const Solution &solution) const
{
    return 0;
}

unsigned Domain::bitsCount() const
{
    return m_bits;
}

unsigned int Domain::solutionSize() const
{
    return m_bits / 8;
}

void Domain::initialize(Solution solution) const
{
    for(int i = 0; i < m_initializers.size(); i++) {

    }
}
