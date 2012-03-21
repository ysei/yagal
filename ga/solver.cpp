#include <cstdlib>
#include "types.h"
#include "domain.h"
#include "space.h"
#include "solver.h"
#include "random.h"

static int compareScores(const void * a, const void * b)
{
    float valA = ((Solver::SolutionScore*)a)->fitness;
    float valB = ((Solver::SolutionScore*)b)->fitness;
    if(valA < valB) {
        return -1;
    } else if(valA > valB) {
        return 1;
    }

    return 0;
}

Solver::Solver(Space * space) : m_space(space), m_scores(NULL),
    m_mutationProbability(0.01f), m_crossoverProbability(0.8f),
    m_acceptableError(0.001f), m_iterations(1000)
{
    m_random = new Random;
}

Solver::~Solver()
{
    if(m_scores) {
        free(m_scores);
    }

    delete m_random;
}

void Solver::setMutationProbability(float probability)
{
    m_mutationProbability = probability;
}

void Solver::setCrossoverProbability(float probability)
{
    m_crossoverProbability = probability;
}

void Solver::setAcceptableError(float acceptableError)
{
    m_acceptableError = acceptableError;
}

void Solver::setIterations(uint maximumAmountOfIterations)
{
    m_iterations = maximumAmountOfIterations;
}

void Solver::run(const Fitness & fitness)
{
    UNUSED(fitness);

    initialize();

    for(uint i = 0; i < m_iterations || m_stats.bestScore > m_acceptableError; i++) {
        step(fitness);
    }
}

void Solver::initialize()
{
    if(m_scores) {
        free(m_scores);
    }

    m_scores = (SolutionScore *)malloc(m_space->size() * sizeof(SolutionScore));
}

void Solver::calculateFitness(const Fitness & fitness)
{
    const Domain * domain = m_space->domain();
    for(uint i = 0; i < m_space->size(); i++)
    {
        m_scores[i].fitness = fitness.calculateFitness(*domain, m_space->solutionAt(i));
        m_scores[i].solutionIndex = i;
    }
}

void Solver::step(const Fitness &fitness)
{
    calculateFitness(fitness);
    sortScores();
    performCrossover();
    performMutation();
}

void Solver::sortScores()
{
    ::qsort(m_scores, m_space->size(), sizeof(SolutionScore), compareScores);
}

void Solver::performCrossover()
{
    uint solutionSize = m_space->domain()->solutionSize();

    for(uint i = 0; i < m_crossoverProbability * m_space->size(); i += 2) {
        byte * solutionDad = m_space->solutionAt(i);
        byte * solutionMom = m_space->solutionAt(i + 1);

        crossover(solutionDad, solutionMom, m_random->uniformInt<uint>(1, solutionSize - 1));

        m_space->domain()->initialize(solutionMom);
    }
}

void Solver::performMutation()
{

}

void Solver::crossover(byte *solutionDad, byte *solutionMom, uint point)
{

}
