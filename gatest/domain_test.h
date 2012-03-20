#ifndef DOMAIN_TEST_H
#define DOMAIN_TEST_H

#include "../ga/domain.h"
#include "gtest/gtest.h"
#include <stdio.h>
TEST(DomainTest, addIntTest) {
    Domain domain;
    domain.add<int>();

    EXPECT_EQ(sizeof(int), domain.solutionSize());
    EXPECT_EQ(sizeof(int) * 8, domain.bitsCount());
}

TEST(DomainTest, add2IntsTest) {
    Domain domain;
    domain.add<int>();
    domain.add<int>();

    EXPECT_EQ(2 * sizeof(int), domain.solutionSize());
    EXPECT_EQ(2 * sizeof(int) * 8, domain.bitsCount());
}

TEST(DomainTest, addFloatTest) {
    Domain domain;
    domain.add<float>();

    EXPECT_EQ(sizeof(float), domain.solutionSize());
    EXPECT_EQ(sizeof(float) * 8, domain.bitsCount());
}

#endif // DOMAIN_TEST_H
