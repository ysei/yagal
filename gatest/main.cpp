#include "gtest/gtest.h"
#include "range_test.h"
#include "domain_test.h"
#include "space_test.h"
#include "solver_test.h"
#include "random_test.h"
#include "operators_test.h"

int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
