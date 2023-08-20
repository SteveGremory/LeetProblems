#pragma once

#include <Arrays/Arrays.hh>
#include <gtest/gtest.h>

static int test_case_number = 1;

inline void print_integer_array(std::vector<int> arr) {
        int len = arr.size();
        std::cerr << "[";
        for (int i = 0; i < len; i++) {
                if (i != 0) {
                        std::cerr << ", ";
                }
                std::cerr << arr[i];
        }
        std::cerr << "]" << std::endl;
}

inline void check(std::vector<int> expected, std::vector<int> output) {
        int expected_size = expected.size();
        int output_size = output.size();

        ASSERT_EQ(expected_size, output_size);

        bool result = true;
        for (int i = 0; i < std::min(expected_size, output_size); i++) {
                result &= (output[i] == expected[i]);
        }

        std::cerr << std::endl;
        EXPECT_TRUE(result) << "Test #" << test_case_number << ": ";

        std::cerr << "Expected: ";
        print_integer_array(expected);

        std::cerr << ("Your output: ");
        print_integer_array(output);
        std::cerr << std::endl;

        test_case_number++;
}