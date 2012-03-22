#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include "../ga/domain.h"
#include "../ga/space.h"
#include "gtest/gtest.h"
#include "common.h"

TEST(TestSpace, testDefaultSize)
{
    Domain domain;
    Space space(&domain);

    EXPECT_EQ(100, space.size());
}

TEST(TestSpace, testSetSize)
{
    Domain domain;
    Space space(&domain);
    space.setSize(123);

    EXPECT_EQ(123, space.size());
}

TEST(TestSpace, testInitialize)
{
    Domain domain;
    domain.add<int>(new ValueInitializer<int>(12345));
    domain.add<float>(new ValueInitializer<float>(123.45f));

    Space space(&domain);
    space.setSize(10);
    space.initialize();

    for(uint i = 0; i < 10; i++) {
        OneIntAndFloatSolution * solution = (OneIntAndFloatSolution *) space.solutionAt(i);
        EXPECT_EQ(12345, solution->n);
        EXPECT_EQ(123.45f, solution->m);
    }
}

TEST(TestSpace, testPromotion)
{
    Domain domain;
    domain.add<int>(new ValueInitializer<int>(7));

    Space space(&domain);
    space.setSize(5);
    space.initialize();

    // Init solutions from 0 to 5
    for(int i = 0; i < 5; i++) {
        OneIntSolution * sol = (OneIntSolution *)space.solutionAt(i);
        sol->n = i;
    }

    // Promote solutions one by one
    for(int i = 0; i < 2; i++) {
        OneIntSolution * sol = (OneIntSolution *)space.solutionFromNewSpaceAt(i);
        sol->n = 0;

        space.promoteSolution(i);
        EXPECT_EQ(sol->n, i);
    }
}

TEST(TestSpace, testSwap)
{
    Domain domain;
    domain.add<int>(new ValueInitializer<int>(8));

    Space space(&domain);
    space.setSize(3);
    space.initialize();

    OneIntSolution * sol = (OneIntSolution *)space.solutionFromNewSpaceAt(0);
    sol->n = 123;

    space.swap();

    sol = (OneIntSolution *)space.solutionAt(0);
    EXPECT_EQ(123, sol->n);
}

TEST(TestSpace, testPromoteAfterSwap)
{
    Domain domain;

    domain.add<int>(new ValueInitializer<int>(8));

    Space space(&domain);
    space.setSize(3);
    space.initialize();

    for(int i = 0; i < 3; i++) {
        space.promoteSolution(i);
    }

    space.swap();

    OneIntSolution * sol = (OneIntSolution *)space.solutionAt(0);
    sol->n = 314;
    space.promoteSolution(0);

    sol = (OneIntSolution *)space.solutionFromNewSpaceAt(0);

    EXPECT_EQ(314, sol->n);
}

#endif // SPACE_TEST_H
