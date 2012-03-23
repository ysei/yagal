#include <assert.h>

#include "types.h"
#include "operators.h"

namespace Operators
{

void crossover(byte * solutionDad, byte * solutionMom, uint size, uint point)
{

}

void mutation(byte * solution, uint size, uint point)
{
    uint byteIndex = point / 8;
    uint bitIndex = point % 8;

    assert(byteIndex < size);

    solution[size - byteIndex - 1] ^= (1 << bitIndex);
}

}
