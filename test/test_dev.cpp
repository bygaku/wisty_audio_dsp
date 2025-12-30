//
// Created by intwi on 2025/12/30.
//

#include <gtest/gtest.h>

// Test - passed.
TEST(passed_test, main) {
	const auto expected = 1;
	const int  actual   = 1;

	ASSERT_EQ(expected, actual);
}

// Test - passed.
TEST(false_test, main) {
	const auto expected = 0;
	const int  actual	= 1;

	ASSERT_FALSE(expected == actual);
}
