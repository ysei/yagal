#ifndef DOMAIN_TEST_H
#define DOMAIN_TEST_H

#include "../ga/domain.h"
#include "gtest/gtest.h"
#include <stdio.h>
TEST(DomainTest, addIntTest) {
    Domain domain;
    domain.addInt();

    EXPECT_EQ(sizeof(int), domain.solutionSize());
    EXPECT_EQ(sizeof(int) * 8, domain.bitsCount());
}

TEST(DomainTest, add2IntsTest) {
    Domain domain;
    domain.addInt();
    domain.addInt();

    EXPECT_EQ(2 * sizeof(int), domain.solutionSize());
    EXPECT_EQ(2 * sizeof(int) * 8, domain.bitsCount());
}

#endif // DOMAIN_TEST_H
