#include <assert.h>

#include "solution.h"
#include "domain.h"
#include "space.h"

Space::Space(const Domain *domain)
    : m_domain(domain), m_size(100), m_solutions(NULL)
{
}

Space::~Space()
{
    free(m_solutions);
}

const Domain * Space::domain() const
{
    return m_domain;
}

void Space::setSize(unsigned int size)
{
    m_size = size;
}

unsigned int Space::size() const
{
    return m_size;
}

Solution Space::solutionAt(unsigned int index)
{
    assert(m_solutions);
    assert(index < m_size);

    return (Solution)((char *)m_solutions + index * m_domain->solutionSize());
}

void Space::createSolutions()
{
    assert(m_size > 0);
    assert(m_domain->bitsCount() > 0);

    if(m_solutions) {
        free(m_solutions);
    }

    m_solutions = malloc(size() * m_domain->solutionSize());
}

void Space::initializeSolutions()
{
    unsigned int solutionSize = m_domain->solutionSize();
    for(int i = 0; i < size(); i++) {
        Solution solution = solutionAt(i);
        m_domain->initialize(solution);
    }
}
