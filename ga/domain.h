#ifndef DOMAIN_H
#define DOMAIN_H

#include <vector>

class Domain
{
public:
    Domain();
    virtual ~Domain();

    void addFloat();
    void addFloat(float min, float max);
    void addInt();
    void addInt(int min, int max);

    template <class T>
    void addArray(int length) {

    }

    float getFloat(int index);
    int getInt(int index);

    template <class T>
    T * getArray(int index) {

    }

    unsigned bitCount() const;

private:
    std::vector<unsigned int> m_valueOffsets;
};

#endif // DOMAIN_H
