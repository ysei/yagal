#ifndef SPACE_H
#define SPACE_H

#include "solution.h"

class Domain;

class Space
{
public:
    /**
      * Creates space of solutions for specified domain.
      */
    Space(const Domain * domain);

    virtual ~Space();

    /**
      * Returns pointer to domain.
      */
    const Domain *domain() const;

    /**
      * Sets size of the space, e.g. amount of solutions.
      * Default is 100.
      */
    void setSize(unsigned int size);

    /**
      * Returns size of the space, e.g. amount of solutions.
      * Default is 100.
      */
    unsigned int size() const;

    Solution solutionAt(unsigned int index);

private:
    void createSolutions();
    void initializeSolutions();

private:
    const Domain * m_domain;
    unsigned int m_size;
    void * m_solutions;
};

#endif // SPACE_H
