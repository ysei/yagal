#ifndef SOLVER_TEST_H
#define SOLVER_TEST_H

#include "../ga/domain.h"
#include "../ga/space.h"
#include "../ga/solver.h"

struct SquareParams {
    float x;
    float y;
};

class SquareFitness : public Fitness
{
public:
    virtual float calculateFitness(const Domain& domain, const byte * solution) const
    {
        UNUSED(domain);

        const SquareParams * params = (const SquareParams *) solution;
        return -((params->x * params->y) + (params->x * params->y));
    }
};

TEST(SolverTest, tryApi)
{
    Domain * domain = new Domain;
    domain->add<float>(); // x
    domain->add<float>(); // y

    Space * space = new Space(domain);
    Solver * solver = new Solver(space);

    SquareFitness squareFitness;
    UNUSED(solver);
    //solver->run(squareFitness);
}

#endif // SOLVER_TEST_H
