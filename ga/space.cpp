#include <assert.h>

#include "domain.h"
#include "space.h"

static const int DEFAULT_SIZE = 100;

Space::Space(Domain *domain)
    : m_domain(domain), m_solutions(NULL), m_newSolutions(NULL),
      m_newSolutionsLastId(0)
{
    setSize(DEFAULT_SIZE);
}

Space::~Space()
{
    free(m_solutions);
    free(m_newSolutions);
}

const Domain * Space::domain() const
{
    return m_domain;
}

void Space::setSize(uint size)
{
    m_size = size;
}

unsigned int Space::size() const
{
    return m_size;
}

byte *Space::solutionAt(uint index)
{
    assert(m_solutions);
    assert(index < m_size);

    return (byte *)(m_solutions + index * m_domain->solutionSize());
}

byte *Space::solutionFromNewSpaceAt(uint index)
{
    assert(m_newSolutions);
    assert(index < m_size);

    return (byte *)(m_newSolutions + index * m_domain->solutionSize());
}

void Space::initialize()
{
    createSolutions();
    initializeSolutions();
}

void Space::promoteSolution(uint index)
{
    assert(index < m_size);
    assert(m_newSolutionsLastId < m_size);

    byte * solutionAtNewSpace = solutionFromNewSpaceAt(m_newSolutionsLastId);
    byte * solution = solutionAt(index);
    uint solutionSize = m_domain->solutionSize();
    ::memcpy(solutionAtNewSpace, solution, solutionSize);
    m_newSolutionsLastId++;
}

void Space::swap()
{
    byte * tmpPtr = m_solutions;
    m_solutions = m_newSolutions;
    m_newSolutions = tmpPtr;

    m_newSolutionsLastId = 0;
}

void Space::createSolutions()
{
    assert(m_size > 0);
    assert(m_domain->solutionSize() > 0);

    uint memoryAreaSize = size() * m_domain->solutionSize();

    if(m_solutions) {
        free(m_solutions);
    }

    m_solutions = (byte *)malloc(memoryAreaSize);

    if(m_newSolutions) {
        free(m_newSolutions);
    }

    m_newSolutions = (byte *)malloc(memoryAreaSize);
    ::memset(m_newSolutions, 0, memoryAreaSize);
}

void Space::initializeSolutions()
{
    for(uint i = 0; i < size(); i++) {
        byte * solution = solutionAt(i);
        m_domain->initialize(solution);
    }
}

void Space::fillRestOfNewSpaceWithRandomSolutions()
{
    for(uint i = m_newSolutionsLastId; i < size(); i++) {
        byte * solution = solutionFromNewSpaceAt(i);
        m_domain->initialize(solution);
    }
}
