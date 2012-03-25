#ifndef RANGE_H
#define RANGE_H

template <class T>
class Range
{

public:
    Range(T range_min, T range_max) : m_range_min(range_min), m_range_max(range_max) {
        m_min = std::numeric_limits<T>::min() / 2;
        T max = std::numeric_limits<T>::max() / 2;

        // Taken from http://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
        factor = (float)(m_range_max - m_range_min) / (max - m_min);
    }

    T scaleToRange(T value) {
        return factor * (value / 2 - m_min) + m_range_min;
    }

private:
    T m_range_min;
    T m_range_max;
    T m_min;
    float factor;
};

#endif // RANGE_H
