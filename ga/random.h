#ifndef RANDOM_H
#define RANDOM_H

#include "RandomLib/Random.hpp"
#include "RandomLib/NormalDistribution.hpp"
#include <assert.h>

class Random
{
public:
    Random();
    virtual ~Random();

    template <class T>
    T uniformInt();

    template <class T>
    T uniformInt(int min, int max);

    template <class T>
    T uniformReal();


    uint gaussianUInt(uint max) {
        assert(max > 0);

        RandomLib::NormalDistribution<double> normDist;
        uint randomUInt = fabs(normDist(m_randomImpl, 0, 0.3)) * max;
        if(randomUInt < max) {
            return randomUInt;
        }

        return max - 1;
    }

private:
    RandomLib::Random m_randomImpl;
};

template <class T>
T Random::uniformInt()
{
    return m_randomImpl.Integer();
}

template <class T>
T Random::uniformInt(int min, int max)
{
    m_randomImpl.IntegerC(min, max);
}

template <class T>
T Random::uniformReal()
{
    return m_randomImpl.Float();
}

#endif // RANDOM_H
