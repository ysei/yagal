#ifndef RANGE_H
#define RANGE_H

template <class T>
struct Range
{
    Range(T range_min, T range_max) : m_range_min(range_min), m_range_max(range_max) {
        float min = std::numeric_limits<T>::min();
        float max = std::numeric_limits<T>::max();

        // factor = (float) ((float)(m_range_max - m_range_min)) / 2.f / (max - min);
        factor = (float)(m_range_max - m_range_min) / (max - min);
    }

    T scaleToRange(T value) {
        return m_range_min + factor * value;
    }

    T m_range_min;
    T m_range_max;
    float factor;
};


#endif // RANGE_H
