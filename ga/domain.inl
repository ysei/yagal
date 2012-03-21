#ifndef DOMAIN_INL
#define DOMAIN_INL

template <class T>
void Domain::add() {
    add<T>(new RandomInitializer<T>);
}

template <class T>
void Domain::add(Initializer * initializer) {
    m_solutionSize += sizeof(T);
    m_valueOffsets.push_back(m_solutionSize);
    m_initializers.push_back(initializer);
}

template <class T>
T Domain::get(unsigned int index, const byte* solution) {
    assert(solution);

    unsigned int offsetInSolution = m_valueOffsets[index];

    return *((T *)(solution + offsetInSolution));
}


#endif // DOMAIN_INL
