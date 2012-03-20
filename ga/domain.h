#ifndef DOMAIN_H
#define DOMAIN_H

#include <assert.h>
#include <vector>
#include "solution.h"

struct Initializer
{
    virtual void initialize(void * ptr)
    {

    }
};

template <class T>
struct RandomInitializer : public Initializer
{
    virtual void initialize(T * ptr)
    {

    }
};

class Domain
{
public:
    Domain();
    virtual ~Domain();

    template <class T>
    void add() {
        m_solutionSize += sizeof(T);
        m_valueOffsets.push_back(m_solutionSize);
    }

    template <class T>
    T get(unsigned int index, const Solution& solution) {
        assert(index >= 0);
        assert(solution);

        unsigned int offsetInSolution = m_valueOffsets[index];
        char * solutionVector = (char *) solution;
        return *((T *)(solutionVector + offsetInSolution));
    }

    unsigned bitsCount() const;
    unsigned int solutionSize() const;

    void initialize(Solution solution) const;

private:
    std::vector<unsigned int> m_valueOffsets;
    std::vector<Initializer *> m_initializers;

    unsigned int m_solutionSize;
};

#endif // DOMAIN_H
