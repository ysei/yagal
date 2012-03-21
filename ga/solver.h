#ifndef SOLVER_H
#define SOLVER_H

class Space;
class Domain;

class Fitness
{
public:
    virtual ~Fitness() {}
    virtual float calculateFitness(const Domain& domain, const byte * solution) = 0;
};

class Solver
{
public:
    Solver(Space * space);

    void run(const Fitness& fitness);

private:
    Space * m_space;
};

#endif // SOLVER_H
