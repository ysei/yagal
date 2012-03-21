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

#endif // SPACE_TEST_H
