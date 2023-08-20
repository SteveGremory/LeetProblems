#include "Arrays.hh"
#include <format>
#include <stack>

namespace Answers::Arrays {
/**
 * Contiguous Subarrays
 * You are given an array arr of N integers. For each index i, you are required
 * to determine the number of contiguous subarrays that fulfill the following
 * conditions: The value at index i must be the maximum element in the
 * contiguous subarrays, and These contiguous subarrays must either start from
 * or end on index i. Signature int[] CountSubarrays(int[] arr) Input Array arr
 * is a non-empty list of unique integers that range between 1 to 1,000,000,000
 * Size N is between 1 and 1,000,000 Output An array where each index i contains
 * an integer denoting the maximum number of contiguous subarrays of arr[i]
 * Example: arr = [3, 4, 1, 6, 2] output = [1, 3, 1, 5, 1] Explanation: For
 * index 0 - [3] is the only contiguous subarray that starts (or ends) with 3,
 * and the maximum value in this subarray is 3. For index 1 - [4], [3, 4], [4,
 * 1] For index 2 - [1] For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1,
 * 6] For index 4 - [2] So, the answer for the above input is [1, 3, 1, 5, 1]
 */
/*
std::vector<int> CountSubarrays(std::vector<int> arr) {
        auto arrsize = arr.size();
        std::vector<int> res{};
        res.reserve(arrsize);

        for (int i = 0; i < arrsize; i++) {
                res.push_back(0);
        }

        assert(arrsize == res.size());

        for (auto idx = 0; idx < arrsize; idx++) {
                res[idx] += 1;

                for (int nextidx = idx + 1; nextidx < arrsize; nextidx++) {
                        if (arr[nextidx] <= arr[idx]) {
                                res[idx] += 1;
                        } else {
                                break;
                        }
                }

                for (int previdx = idx - 1; previdx >= 0; previdx--) {

                        if (arr[previdx] <= arr[idx]) {
                                res[idx] += 1;
                        } else {
                                break;
                        }
                }
        }

        return res;
}
*/

auto CountSubarrays(std::vector<int> arr) -> std::vector<int> {
        auto res = std::vector(arr.size(), 1);
        auto stack = std::stack<int>{};
        auto rstack = std::stack<int>{};

        for (auto i = 1; i < arr.size(); i++) {
                auto j = arr.size() - i - 1;
                stack.push(i - 1);
                rstack.push(j + 1);

                while (!(stack.empty()) && arr[stack.top()] < arr[i]) {
                        res[stack.top()] += i - stack.top() - 1;
                        stack.pop();
                }

                while (!(rstack.empty()) && arr[rstack.top()] < arr[j]) {
                        res[rstack.top()] += rstack.top() - j - 1;
                        rstack.pop();
                }
        }

        while (!stack.empty()) {
                res[stack.top()] += (arr.size() - 1) - stack.top();
                stack.pop();
        }

        while (!rstack.empty()) {
                res[rstack.top()] += rstack.top();
                rstack.pop();
        }

        return res;
}

} // namespace Answers::Arrays
