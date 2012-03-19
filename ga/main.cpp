#include <stdio.h>
#include "yagal.h"

class SquareFitnes : public Fitness
{
public:
    virtual float calculateFitness(const Domain &domain, const Solution &solution) {
        float x = domain.getFloat(0, solution);
        return x * x;
    }
};

int main(int /* argc */, char ** /* argv */)
{
    Domain * domain = new Domain;
    domain->addFloat();
    Space * space = new Space(domain);
    space->setSize(200);
    Solver * solver = new Solver(space);

    SquareFitnes fitness;
    solver->run(fitness);

    return 0;
}
