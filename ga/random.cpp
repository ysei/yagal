#include "types.h"
#include "random.h"

Random::Random()
{
    m_randomImpl.Reseed();
}

Random::~Random()
{

}
