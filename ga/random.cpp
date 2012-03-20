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

// The following random number generators are from Numerical Recipes in C.
// I have split them into a seed function and random number function.

// The ran1 pseudo-random number generator.  This one is OK to use as long as
// you don't call it more than about 10^8 times, so for any long GA runs you'd
// better use something with a longer period.

#if defined(YAGAL_USE_RAN1)

#define IA 16807L
#define IM 2147483647L
#define AM (1.0/IM)
#define IQ 127773L
#define IR 2836L
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

static long iy=0;
static long iv[NTAB];
static long idum=0;

void
gasran1(unsigned int seed) {
    int j;
    long k;

    idum = seed;
    if (idum == 0) idum=1;
    if (idum < 0) idum = -idum;
    for (j=NTAB+7;j>=0;j--) {
        k=(idum)/IQ;
        idum=IA*(idum-k*IQ)-IR*k;
        if (idum < 0) idum += IM;
        if (j < NTAB) iv[j] = idum;
    }
    iy=iv[0];
}

float garan1() {
    int j;
    long k;
    float temp;

    k=(idum)/IQ;
    idum=IA*(idum-k*IQ)-IR*k;
    if (idum < 0) idum += IM;
    j=iy/NDIV;
    iy=iv[j];
    iv[j] = idum;
    if ((temp=AM*iy) > RNMX) return RNMX;
    else return temp;
}

#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX

#endif




// The ran2 pseudo-random number generator.  It has a period of 2 * 10^18 and
// returns a uniform random deviate on the interval (0.0, 1.0) excluding the
// end values.  idum initializes the sequence, so we create a separate seeding
// function to set the seed.  If you reset the seed then you re-initialize the
// sequence.

#if defined(YAGAL_USE_RAN2)

#define IM1 2147483563L
#define IM2 2147483399L
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014L
#define IA2 40692L
#define IQ1 53668L
#define IQ2 52774L
#define IR1 12211L
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

static long idum2=123456789;
static long iy=0;
static long iv[NTAB];
static long idum=0;

void
gasran2(unsigned int seed) {
    int j;
    long k;

    idum = STA_CAST(long,seed);
    if (idum == 0) idum=1;
    if (idum < 0) idum = -idum;
    idum2=(idum);
    for (j=NTAB+7;j>=0;j--) {
        k=(idum)/IQ1;
        idum=IA1*(idum-k*IQ1)-k*IR1;
        if (idum < 0) idum += IM1;
        if (j < NTAB) iv[j] = idum;
    }
    iy=iv[0];
}

float
garan2() {
    int j;
    long k;
    float temp;

    k=(idum)/IQ1;
    idum=IA1*(idum-k*IQ1)-k*IR1;
    if (idum < 0) idum += IM1;
    k=idum2/IQ2;
    idum2=IA2*(idum2-k*IQ2)-k*IR2;
    if (idum2 < 0) idum2 += IM2;
    j=iy/NDIV;
    iy=iv[j]-idum2;
    iv[j] = idum;
    if (iy < 1) iy += IMM1;
    if ((temp=AM*iy) > RNMX) return RNMX;
    else return temp;
}

#undef IM1
#undef IM2
#undef AM
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX

#endif


#if defined(YAGAL_USE_RAN3)

// The ran3 pseudo-random number generator.  It is *not* linear congruential.

#define MBIG 1000000000
#define MSEED 161803398
#define MZ 0
#define FAC (1.0/MBIG)

static int inext,inextp;
static long ma[56];

void
gasran3(unsigned int seed) {
    long idum = seed;
    long mj,mk;
    int i,ii,k;

    mj=labs(MSEED-labs(idum));
    mj %= MBIG;
    ma[55]=mj;
    mk=1;
    for (i=1;i<=54;i++) {
        ii=(21*i) % 55;
        ma[ii]=mk;
        mk=mj-mk;
        if (mk < MZ) mk += MBIG;
        mj=ma[ii];
    }
    for (k=1;k<=4;k++)
        for (i=1;i<=55;i++) {
            ma[i] -= ma[1+(i+30) % 55];
            if (ma[i] < MZ) ma[i] += MBIG;
        }
    inext=0;
    inextp=31;
}

float
garan3() {
    long mj;
    int i,ii,k;

    if (++inext == 56) inext=1;
    if (++inextp == 56) inextp=1;
    mj=ma[inext]-ma[inextp];
    if (mj < MZ) mj += MBIG;
    ma[inext]=mj;
    return mj*FAC;
}

#undef MBIG
#undef MSEED
#undef MZ
#undef FAC

#endif
