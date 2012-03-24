#include <stdio.h>

#include <stdio.h>
#include <ga/ga.h>
#include <ga/std_stream.h>

#define cout STD_COUT

float objective(GAGenome &);

int main(int, char **)
{
    unsigned int seed = 0;

    // Declare variables for the GA parameters and set them to some default values.

    int popsize  = 50;
    int ngen     = 100;
    float pmut   = 0.01;
    float pcross = 0.6;

    GABin2DecPhenotype map;
    map.add(16, -5, 5);
    map.add(16, -5, 5);

    GABin2DecGenome genome(map, objective);

    GASimpleGA ga(genome);
    GASigmaTruncationScaling scaling;
    ga.populationSize(popsize);
    ga.nGenerations(ngen);
    ga.pMutation(pmut);
    ga.pCrossover(pcross);
    ga.scaling(scaling);
    ga.evolve(seed);

    genome = ga.statistics().bestIndividual();
    cout << "the ga found an optimum at the point (";
    cout << genome.phenotype(0) << ", " << genome.phenotype(1) << ")\n\n";
    cout << "best of generation data are in '" << ga.scoreFilename() << "'\n";

    return 0;
}

// Minimum is good
float objective(GAGenome & c)
{
    GABin2DecGenome & genome = (GABin2DecGenome &)c;

    float y;
    y = -genome.phenotype(0) * genome.phenotype(0);
    y -= genome.phenotype(1) * genome.phenotype(1);
    return y;
}
