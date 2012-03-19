#ifndef DOMAIN_H
#define DOMAIN_H

#include <vector>
#include "solution.h"

template <class T>
struct RandomInitializer
{
    virtual T operator ()();
};

template <class T>
struct Initializer
{

    virtual T operator ()();
};

class Domain
{
public:
    Domain();
    virtual ~Domain();

    template <class T>
    void add() {

    }

    template <class T>
    void add(const RandomInitializer * initializer) {

    }

    void addFloat();
    void addInt();

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
    std::vector<RandomInitializer *> m_initializers;

    unsigned int m_bits;
};

#endif // DOMAIN_H
