#ifndef SOLVER_H
#define SOLVER_H

class Space;

class Solver
{
public:
    Solver(Space * space);

private:
    Space * m_space;
};

#endif // SOLVER_H
