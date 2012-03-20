#include "domain.h"
#include "solution.h"

Domain::Domain() : m_solutionSize(0)
{
    m_valueOffsets.push_back(0);
}

Domain::~Domain()
{

}

unsigned Domain::bitsCount() const
{
    return m_solutionSize * 8;
}

unsigned int Domain::solutionSize() const
{
    return m_solutionSize;
}

void Domain::initialize(Solution solution) const
{
    for(int i = 0; i < m_initializers.size(); i++) {

    }
}
