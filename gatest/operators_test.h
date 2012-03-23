#ifndef OPERATORS_TEST_H
#define OPERATORS_TEST_H

#include "../ga/operators.h"

TEST(OperatorsTest, testMutationByte)
{
    byte b1 = 0;    // 00000000
    byte b2 = 2;    // 00000010
    byte b3 = 0x80; // 10000000

    Operators::mutation(&b1, 1, 1);
    EXPECT_EQ(2, b1);

    Operators::mutation(&b2, 1, 1);
    EXPECT_EQ(0, b2);

    Operators::mutation(&b3, 1, 7);
    EXPECT_EQ(0, b3);
}

TEST(OperatorsTest, testMutationTwoBytes)
{
    const byte K = 64; // Just a non zero constant
    byte b1[2] = {K, 2};
    byte b2[2] = {2, K};
    byte b3[2] = {0x80, K};

    Operators::mutation(b1, 2, 1);
    EXPECT_EQ(K, b1[0]);
    EXPECT_EQ(0, b1[1]);

    Operators::mutation(b2, 2, 9);
    EXPECT_EQ(0, b2[0]);
    EXPECT_EQ(K, b2[1]);

    Operators::mutation(b3, 2, 15);
    EXPECT_EQ(0, b3[0]);
    EXPECT_EQ(K, b3[1]);
}

#endif // OPERATORS_TEST_H
