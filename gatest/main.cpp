#include "gtest/gtest.h"
#include "range_test.h"

int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}