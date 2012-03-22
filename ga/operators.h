#ifndef OPERATORS_H
#define OPERATORS_H

namespace Operators
{

void crossover(byte * solutionDad, byte * solutionMom, uint size, uint point);
void mutation(byte * solution, uint size, uint point);

}

#endif // OPERATORS_H
