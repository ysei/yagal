#ifndef SPACE_H
#define SPACE_H

class Domain;

class Space
{
public:
    /**
      * Creates space of solutions for specified domain.
      */
    Space(Domain *domain);

    virtual ~Space();

    /**
      * Returns pointer to domain.
      */
    const Domain *domain() const;

    /**
      * Sets size of the space, e.g. amount of solutions.
      * Default is 100.
      */
    void setSize(uint size);

    /**
      * Returns size of the space, e.g. amount of solutions.
      * Default is 100.
      */
    unsigned int size() const;

    byte *solutionAt(uint index);

    void initialize();

private:
    void createSolutions();
    void initializeSolutions();

private:
    Domain * m_domain;
    unsigned int m_size;
    byte * m_solutions;
};

#endif // SPACE_H
