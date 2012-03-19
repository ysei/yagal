#ifndef RANGE_TEST_H__
#define RANGE_TEST_H__

#include "../ga/range.h"
#include "gtest/gtest.h"

TEST(RangeTest, CharTest) {
    Range<char> r(-12, 10);

    EXPECT_EQ(10, r.scaleToRange(std::numeric_limits<char>::max()));
    // EXPECT_EQ(1, r.scaleToRange(std::numeric_limits<char>::min()));
    // EXPECT_EQ(5, r.scaleToRange(0));
}

#endif
