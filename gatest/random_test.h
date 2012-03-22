#ifndef RANDOM_TEST_H
#define RANDOM_TEST_H

#include <vector>
#include "../ga/random.h"
#include "gtest/gtest.h"


TEST(RandomTest, gaussianUIntDistribution)
{
    Random r;
    std::vector<uint> values;
    // 10000 is enough to see how values from 0 to 9 are distributed.
    // Most of the values should be of 0, then of 1 and so on.
    for(size_t i = 0; i < 10000; i++) {
        values.push_back(r.gaussianUInt(10));
    }

    for(int i = 0; i < 10; i += 2) {
        int hI = std::count(values.begin(), values.end(), i);
        int hII = std::count(values.begin(), values.end(), i + 1);
        EXPECT_GE(hI, hII);
    }
}

#endif // RANDOM_TEST_H
