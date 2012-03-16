#ifndef SPACE_H
#define SPACE_H

class Domain;

class Space
{
public:
    Space(const Domain * domain);

    const Domain *domain() const;

private:
    const Domain * m_domain;
};

#endif // SPACE_H
