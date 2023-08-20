#include "common.hh"

TEST(Arrays, PassingYearBook) {
        std::vector<int> arr_1 = {2, 1};
        std::vector<int> expected_1 = {2, 2};
        std::vector<int> output_1 = Answers::Arrays::FindSignatureCounts(arr_1);
        check(expected_1, output_1);

        std::vector<int> arr_2 = {1, 2};
        std::vector<int> expected_2 = {1, 1};
        std::vector<int> output_2 = Answers::Arrays::FindSignatureCounts(arr_2);
        check(expected_2, output_2);

        // Add your own test cases here
        std::vector<int> arr_3 = {3, 2, 1};
        std::vector<int> expected_3 = {2, 1, 2};
        std::vector<int> output_3 = Answers::Arrays::FindSignatureCounts(arr_3);
        check(expected_3, output_3);

        std::vector<int> arr_4 = {2, 1, 3};
        std::vector<int> expected_4 = {2, 2, 1};
        std::vector<int> output_4 = Answers::Arrays::FindSignatureCounts(arr_4);
        check(expected_4, output_4);
}