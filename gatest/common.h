#ifndef COMMON_H
#define COMMON_H

#include "ga/initializer.h"

struct OneIntSolution {
    int n;
};

struct TwoIntsSolution {
    int n;
    int m;
};

struct OneIntAndFloatSolution {
    int n;
    float m;
};

template <class T>
struct ValueInitializer : public Initializer
{
    ValueInitializer(T v) : value(v) {}

    virtual void initialize(void * ptr) {
        T * p = (T *) ptr;
        *p = value;
    }

    T value;
};

#endif // COMMON_H
