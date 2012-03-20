#ifndef DOMAIN_H
#define DOMAIN_H

#include <assert.h>
#include <vector>
#include "types.h"
#include "solution.h"

struct Initializer
{
    virtual void initialize(void * ptr)
    {
        UNUSED(ptr);
    }
};

template <class T>
struct RandomInitializer : public Initializer
{
    virtual void initialize(T * ptr)
    {
        UNUSED(ptr);
    }
};

class Domain
{
public:
    Domain();
    virtual ~Domain();

    template <class T>
    void add() {
        add<T>(new RandomInitializer<T>);
    }

    template <class T>
    void add(Initializer * initializer) {
        m_solutionSize += sizeof(T);
        m_valueOffsets.push_back(m_solutionSize);
        m_initializers.push_back(initializer);
    }

    template <class T>
    T get(unsigned int index, const byte* solution) {
        assert(index >= 0);
        assert(solution);

        unsigned int offsetInSolution = m_valueOffsets[index];

        return *((T *)(solution + offsetInSolution));
    }

    unsigned bitsCount() const;
    unsigned int solutionSize() const;

    void initialize(byte * solution) const;

private:
    void * ptrToComponent(uint index, byte * solution) const;

private:
    std::vector<uint> m_valueOffsets;
    std::vector<Initializer *> m_initializers;

    unsigned int m_solutionSize;
};

#endif // DOMAIN_H
