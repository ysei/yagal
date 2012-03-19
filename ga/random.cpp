#include "random.h"

static unsigned int g_seed;

void fast_srand(int seed)
{
    g_seed = seed;
}

int fastrand()
{
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}
