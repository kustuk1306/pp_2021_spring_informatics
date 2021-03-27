// Copyright 2021 Zaitsev Andrey
#include <gtest/gtest.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "./RadixSortSeq.h"

TEST(Test_Seq, Vector_One_El) {
	int size = 1;
	std::vector<double> vec = createVector(size, 0.0, 10.0);
	std::vector<double> vec2 = radixSort(vec, size);
	std::sort(vec.begin(), vec.end());
	ASSERT_EQ(vec2, vec);
}

TEST(Test_Seq, Size_5_Pos_And_Neg) {
	int size = 5;
	std::vector<double> vec = { 4.33, -6.541, 16.84, 2.662, -12.544 };
	std::vector<double> vec2 = radixSort(vec, size);
	std::sort(vec.begin(), vec.end());
	ASSERT_EQ(vec2, vec);
}

TEST(Test_Seq, Random_Size_1000_Positive) {
	int size = 1000;
	std::vector<double> vec = createVector(size, 100.0, 1000.0);
	std::vector<double> vec2 = radixSort(vec, size);
	std::sort(vec.begin(), vec.end());
	ASSERT_EQ(vec2, vec);
}

TEST(Test_Seq, Random_Size_1000_Negative) {
	int size = 1000;
	std::vector<double> vec = createVector(size, -800.0, 0.0);
	std::vector<double> vec2 = radixSort(vec, size);
	std::sort(vec.begin(), vec.end());
	ASSERT_EQ(vec2, vec);
}

TEST(Test_Seq, Exact_Answer) {
	int size = 7;
	std::vector<double> vec = {5.32, 8.25, 3.463, 43.733, 120.632, 75.86, 53.41};
	std::vector<double> answer = {3.463, 5.32, 8.25, 43.733, 53.41, 75.86, 120.632};
	vec = radixSort(vec, size);
	for(int i = 0; i < size; i++)
		ASSERT_NEAR(vec[i], answer[i], 0.01);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}