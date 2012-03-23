#include <assert.h>

#include "types.h"
#include "operators.h"

namespace Operators
{

void crossover(byte * solutionDad, byte * solutionMom, uint size, uint point)
{
    assert(size * 8 > point);

    uint byteIndex = point / 8;
    uint bitIndex = point % 8;

    for(uint i = byteIndex + 1; i < size; i++) {
        solutionDad[i] = solutionMom[i];
    }

    if(bitIndex != 0) {
        byte crossoverByteDad = solutionDad[byteIndex];
        byte crossoverByteMom = solutionMom[byteIndex];

        crossoverByteDad >>= bitIndex;
        crossoverByteDad <<= bitIndex;

        crossoverByteMom <<= (8 - bitIndex);
        crossoverByteMom >>= (8 - bitIndex);

        solutionDad[byteIndex] = crossoverByteDad | crossoverByteMom;
    }
}

void mutation(byte * solution, uint size, uint point)
{
    uint byteIndex = point / 8;
    uint bitIndex = point % 8;

    assert(byteIndex < size);

    solution[size - byteIndex - 1] ^= (1 << bitIndex);
}

}
