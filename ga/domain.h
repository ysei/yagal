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
    virtual void initialize(void * ptr)
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
    void add();

    template <class T>
    void add(Initializer * initializer);

    template <class T>
    T get(unsigned int index, const byte* solution);

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

#include "domain.inl"

#endif // DOMAIN_H
