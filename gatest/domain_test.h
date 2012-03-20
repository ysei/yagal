#ifndef DOMAIN_TEST_H
#define DOMAIN_TEST_H

#include "../ga/domain.h"
#include "gtest/gtest.h"

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

TEST(DomainTest, addIntAndFloatTest) {
    Domain domain;
    domain.add<int>();
    domain.add<float>();

    EXPECT_EQ(sizeof(float) + sizeof(int), domain.solutionSize());
    EXPECT_EQ((sizeof(float) + sizeof(int)) * 8, domain.bitsCount());
}

struct OneIntSolution {
    int n;
};

TEST(DomainTest, getIntTest) {
    OneIntSolution sol;
    sol.n = 546;

    Domain domain;
    domain.add<int>();

    EXPECT_EQ(546, domain.get<int>(0, (Solution)&sol));
}

struct TwoIntsSolution {
    int n;
    int m;
};

TEST(DomainTest, get2IntsTest) {
    TwoIntsSolution sol;
    sol.n = 7648;
    sol.m = -1454;

    Domain domain;
    domain.add<int>();
    domain.add<int>();

    EXPECT_EQ(7648, domain.get<int>(0, (Solution)&sol));
    EXPECT_EQ(-1454, domain.get<int>(1, (Solution)&sol));
}

#endif // DOMAIN_TEST_H
