#include "common.hh"

TEST(Arrays, ContiguousSubarrays) {
        std::vector<int> test_1 = {3, 4, 1, 6, 2};
        std::vector<int> expected_1 = {1, 3, 1, 5, 1};
        std::vector<int> output_1 = Answers::Arrays::CountSubarrays(test_1);
        check(expected_1, output_1);

        std::vector<int> test_2 = {2, 4, 7, 1, 5, 3};
        std::vector<int> expected_2 = {1, 2, 6, 1, 3, 1};
        std::vector<int> output_2 = Answers::Arrays::CountSubarrays(test_2);
        check(expected_2, output_2);

        std::vector<int> test_3 = {3, 3, 5, 2, 2};
        std::vector<int> expected_3 = {2, 2, 5, 2, 2};
        std::vector<int> output_3 = Answers::Arrays::CountSubarrays(test_3);
        check(expected_3, output_3);

        test_case_number = 0;
}