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

TEST(OperatorsTest, testOneByteCrossover)
{
    byte b1 = 0x13;
    byte b2 = 0x25;
    const byte expected = 0x15;

    // Left half of the byte will be taken from dad
    // Right half of the byte will be taken from mom
    Operators::crossover(&b1, &b2, 1, 4);
    EXPECT_EQ(expected, b1);
}

TEST(OperatorsTest, testOneBytePoint2Crossover)
{
    byte b1 = 0xFE;
    byte b2 = 0x00;
    const byte expected = 0x80;

    Operators::crossover(&b1, &b2, 1, 7);
    EXPECT_EQ(expected, b1);
}

TEST(OperatorsTest, testOneBytePointIs2Crossover)
{
    byte b1 = 0xFE;
    byte b2 = 0x00;
    const byte expected = 0xFC;

    Operators::crossover(&b1, &b2, 1, 2);
    EXPECT_EQ(expected, b1);
}

TEST(OperatorsTest, testThreeBytesCrossover)
{
    byte b1[3] = {0x32, 0x2A, 0x19};
    byte b2[3] = {0xA2, 0x35, 0x89};

    Operators::crossover(b1, b2, 3, 12);
    EXPECT_EQ(0x32, b1[0]); // Comes from dad
    EXPECT_EQ(0x25, b1[1]); // Comes from both
    EXPECT_EQ(0x89, b1[2]); // Comes from mom
}

#endif // OPERATORS_TEST_H
