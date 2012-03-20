#ifndef DOMAIN_H
#define DOMAIN_H

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
        m_bits += sizeof(T) * 8;
        m_valueOffsets.push_back(m_bits);
    }

    template <class T>
    void addArray(int length) {

    }

    float getFloat(int index, const Solution& solution) const;
    int getInt(int index, const Solution& solution) const;

    template <class T>
    T * getArray(int index, const Solution& solution) const {

    }

    unsigned bitsCount() const;
    unsigned int solutionSize() const;

    void initialize(Solution solution) const;

private:
    std::vector<unsigned int> m_valueOffsets;
    std::vector<Initializer *> m_initializers;

    unsigned int m_bits;
};

#endif // DOMAIN_H
