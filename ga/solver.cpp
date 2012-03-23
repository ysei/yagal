#include <cstdlib>
#include "types.h"
#include "domain.h"
#include "space.h"
#include "solver.h"
#include "random.h"
#include "operators.h"

static int compareScores(const void * a, const void * b)
{
    float valA = ((Solver::SolutionScore*)a)->fitness;
    float valB = ((Solver::SolutionScore*)b)->fitness;
    if(valA < valB) {
        return 1;
    } else if(valA > valB) {
        return -1;
    }

    return 0;
}

Solver::Solver(Space * space) : m_space(space), m_scores(NULL),
    m_newSpaceSolutionId(0), m_mutationProbability(0.01f),
    m_crossoverProbability(0.8f), m_acceptableError(0.001f),
    m_iterations(1000)
{
    m_random = new Random;
    m_stats.bestSolution = NULL;
}

Solver::~Solver()
{
    if(m_scores) {
        free(m_scores);
    }

    delete m_random;


    if(m_stats.bestSolution) {
        free(m_stats.bestSolution);
    }
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
    initialize();

    for(uint i = 0; i < m_iterations || m_stats.bestScore > m_acceptableError; i++) {
        step(fitness);
    }
}

const Solver::SolverStatistics &Solver::stats() const
{
    return m_stats;
}

void Solver::initialize()
{
    if(m_scores) {
        free(m_scores);
    }

    m_scores = (SolutionScore *)malloc(m_space->size() * sizeof(SolutionScore));

    m_space->initialize();

    if(m_stats.bestSolution) {
        free(m_stats.bestSolution);
    }

    ::memset(&m_stats, 0, sizeof(SolverStatistics));

    m_stats.bestSolution = (byte *) malloc(m_space->domain()->solutionSize());
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
    updateBestSolution();

    for(uint i = 0; i < m_space->size(); i++) {
        performCrossover(i);
        performMutation(i);
    }

    m_space->swap();
}

void Solver::sortScores()
{
    ::qsort(m_scores, m_space->size(), sizeof(SolutionScore), compareScores);
}

void Solver::performCrossover(uint solutionIndex)
{
    if(m_random->prob(m_crossoverProbability)) {        
        uint solutionSize = m_space->domain()->solutionSize();

        uint crossoverMate = m_scores[m_random->gaussianUInt(m_space->size())].solutionIndex;
        if(crossoverMate != solutionIndex) {
            m_stats.crossovers++;
            byte * solutionDad = m_space->solutionAt(solutionIndex);
            byte * solutionMom = m_space->solutionAt(crossoverMate);
            uint crossoverPoint = m_random->uniformInt<uint>(1, solutionSize);
            Operators::crossover(solutionDad, solutionMom, solutionSize, crossoverPoint);
            m_space->promoteSolution(solutionIndex);
        }
    }
}

void Solver::performMutation(uint solutionIndex)
{
    if(m_random->prob(m_mutationProbability)) {
        m_stats.mutations++;
        uint solutionSize = m_space->domain()->solutionSize();

        byte * solution = m_space->solutionAt(solutionIndex);
        uint mutationPoint = m_random->uniformInt<uint>(1, solutionSize);
        Operators::mutation(solution, solutionSize, mutationPoint);
        m_space->promoteSolution(solutionIndex);
    }
}

void Solver::updateBestSolution()
{
    if(m_scores[0].fitness < m_stats.bestScore) {
        m_stats.bestScore = m_scores[0].fitness;
        ::memcpy(m_stats.bestSolution, m_space->solutionAt(m_scores[0].solutionIndex), m_space->domain()->solutionSize());
    }
}
