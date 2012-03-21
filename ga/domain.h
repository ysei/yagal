#ifndef DOMAIN_H
#define DOMAIN_H

#include <assert.h>
#include <vector>
#include "types.h"
#include "solution.h"
#include "random.h"

class Initializer
{
public:
    virtual ~Initializer() {}
    virtual void initialize(void * ptr) = 0;
};

template <class T>
class RandomInitializer : public Initializer
{
public:
    virtual void initialize(void * ptr){
        uint bytes = sizeof(T);
        byte * bPtr = (byte *)ptr;
        for(uint i = 0; i < bytes; i++) {
            bPtr[i] = m_random.uniformInt<byte>();
        }
    }

private:
    Random m_random;
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

    void initialize(byte * solution);

private:
    void * ptrToComponent(uint index, byte * solution) const;

private:
    std::vector<uint> m_valueOffsets;
    std::vector<Initializer *> m_initializers;

    unsigned int m_solutionSize;
    Random m_random;
};


#include "domain.inl"

#endif // DOMAIN_H
