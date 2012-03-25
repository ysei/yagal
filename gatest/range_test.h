#ifndef RANGE_TEST_H__
#define RANGE_TEST_H__

#include "../ga/range.h"
#include "gtest/gtest.h"

template<class T>
void testScaleToRange(T min, T max, T value, T expected)
{
    Range<T> r(min, max);

    EXPECT_EQ(max, r.scaleToRange(std::numeric_limits<T>::max()));
    EXPECT_EQ(min, r.scaleToRange(std::numeric_limits<T>::min()));
    EXPECT_EQ(expected, r.scaleToRange(value));
}

TEST(RangeTest, TestPositiveScale) {
    testScaleToRange<char>(0, 10, 0, 5);
    testScaleToRange<short>(0, 10, 0, 5);
    testScaleToRange<int>(0, 10, 0, 5);
    testScaleToRange<long>(0, 10, 0, 5);
}

TEST(RangeTest, TestPositiveAndNegativeScale) {
    testScaleToRange<char>(-10, 10, 0, 0);
    testScaleToRange<short>(-10, 10, 0, 0);
    testScaleToRange<int>(-10, 10, 0, 0);
    testScaleToRange<long>(-10, 10, 0, 0);
}

TEST(RangeTest, TestNegativeScale) {
    testScaleToRange<char>(-10, 0, 0, -4);
    testScaleToRange<short>(-10, 0, 0, -4);
    testScaleToRange<int>(-10, 0, 0, -5);
    testScaleToRange<long>(-10, 0, 0, -5);
}

#endif
