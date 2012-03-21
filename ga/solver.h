#ifndef SOLVER_H
#define SOLVER_H

#include "types.h"

class Space;
class Domain;
class Random;

class Fitness
{
public:
    virtual ~Fitness() {}
    virtual float calculateFitness(const Domain& domain, const byte * solution) const = 0;
};

class Solver
{
public:
    struct SolverStatistics
    {
        ulong mutations;
        ulong crossovers;
        float bestScore;
        uint bestSolutionIndex;
    };

    struct SolutionScore {
        float fitness;
        uint solutionIndex;
    };

    Solver(Space * space);
    virtual ~Solver();

    void setMutationProbability(float probability);
    void setCrossoverProbability(float probability);
    void setAcceptableError(float acceptableError);
    void setIterations(uint maximumAmountOfIterations);

    void run(const Fitness& fitness);

protected:
    void initialize();
    void calculateFitness(const Fitness &fitness);
    void step(const Fitness & fitness);
    void sortScores();
    void performCrossover();
    void performMutation();

    void crossover(byte * solutionDad, byte * solutionMom, uint point);

private:
    Space * m_space;
    SolutionScore * m_scores;

    float m_mutationProbability;
    float m_crossoverProbability;
    float m_acceptableError;
    uint m_iterations;
    SolverStatistics m_stats;
    Random * m_random;
};

#endif // SOLVER_H
