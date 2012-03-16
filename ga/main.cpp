#include "ga.h"

int main(int argc, char * argv[])
{
    Domain * domain = new Domain;
    Space * space = new Space(domain);
    Solver * solver = new Solver(space);
    return 0;
}
