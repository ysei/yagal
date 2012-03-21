#include "types.h"
#include "domain.h"
#include "random.h"

Domain::Domain() : m_solutionSize(0), m_random(new Random())
{
    m_valueOffsets.push_back(0);    
}

Domain::~Domain()
{
    delete m_random;
}

unsigned Domain::bitsCount() const
{
    return m_solutionSize * 8;
}

unsigned int Domain::solutionSize() const
{
    return m_solutionSize;
}

void Domain::initialize(byte *solution)
{
    for(uint i = 0; i < m_initializers.size(); i++) {
        Initializer * initializer = m_initializers[i];
        void * ptrToCmp = ptrToComponent(i, solution);
        initializer->initialize(ptrToCmp);
    }
}

void *Domain::ptrToComponent(uint index, byte *solution) const
{
    assert(index < m_valueOffsets.size());

    uint offset = m_valueOffsets[index];
    return (void *)(solution + offset);
}
