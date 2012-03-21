#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "types.h"
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

#endif // INITIALIZER_H
