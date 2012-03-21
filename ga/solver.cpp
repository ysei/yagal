#include "types.h"
#include "space.h"
#include "solver.h"

Solver::Solver(Space * space) : m_space(space)
{
}

void Solver::run(const Fitness & fitness)
{
    UNUSED(fitness);
}
