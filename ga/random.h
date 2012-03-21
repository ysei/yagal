#ifndef RANDOM_H
#define RANDOM_H

#include "RandomLib/Random.hpp"

class Random
{
public:
    Random();
    virtual ~Random();

    template <class T>
    T uniformInt();

    template <class T>
    T uniformReal();

private:
    RandomLib::Random m_randomImpl;
};


template <class T>
T Random::uniformInt() {
    return m_randomImpl.Integer();
}

template <class T>
T Random::uniformReal() {
    return m_randomImpl.Float();
}

#endif // RANDOM_H
