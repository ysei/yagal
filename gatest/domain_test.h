#ifndef DOMAIN_TEST_H
#define DOMAIN_TEST_H

#include "../ga/domain.h"
#include "gtest/gtest.h"
#include "RandomLib/Random.hpp"
#include "common.h"

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

TEST(DomainTest, getIntTest) {
    OneIntSolution sol;
    sol.n = 546;

    Domain domain;
    domain.add<int>();

    EXPECT_EQ(546, domain.get<int>(0, (byte *)&sol));
}

TEST(DomainTest, get2IntsTest) {
    TwoIntsSolution sol;
    sol.n = 7648;
    sol.m = -1454;

    Domain domain;
    domain.add<int>();
    domain.add<int>();

    EXPECT_EQ(7648, domain.get<int>(0, (byte *)&sol));
    EXPECT_EQ(-1454, domain.get<int>(1, (byte *)&sol));
}

TEST(DomainTest, getOneIntAndFloatTest) {
    OneIntAndFloatSolution sol;
    sol.n = 3945;
    sol.m = -40.195f;

    Domain domain;
    domain.add<int>();
    domain.add<float>();

    EXPECT_EQ(3945, domain.get<int>(0, (byte *)&sol));
    EXPECT_EQ(-40.195f, domain.get<float>(1, (byte *)&sol));
}

TEST(DomainTest, initializeOneInt) {
    OneIntSolution sol;
    sol.n = 0;

    Domain domain;
    domain.add<int>(new ValueInitializer<int>(123));

    domain.initialize((byte *)&sol);

    EXPECT_EQ(123, sol.n);
}

TEST(DomainTest, initializeIntAndFloat) {
    OneIntAndFloatSolution sol;
    sol.n = 0;
    sol.m = 0;

    Domain domain;
    domain.add<int>(new ValueInitializer<int>(324));
    domain.add<float>(new ValueInitializer<float>(40.2354f));

    domain.initialize((byte *)&sol);

    EXPECT_EQ(324, sol.n);
    EXPECT_EQ(40.2354f, sol.m);
}

TEST(DomainTest, initializeSolutionRandomly) {
    OneIntAndFloatSolution sol;
    ::memset(&sol, 0, sizeof(OneIntAndFloatSolution));

    Domain domain;
    domain.add<int>();
    domain.add<float>();

    domain.initialize((byte *)&sol);

    EXPECT_NE(0, sol.n);
    EXPECT_NE(0.0f, sol.m);
}

#endif // DOMAIN_TEST_H
