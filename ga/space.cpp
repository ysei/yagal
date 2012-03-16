#include "space.h"

Space::Space(const Domain *domain)
    : m_domain(domain)
{
}

const Domain * Space::domain() const
{
    return m_domain;
}
