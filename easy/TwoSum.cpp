#include <vector>
#include <cassert>
#include <iostream>
#include <unordered_map>

//
// Created by Danil on 19.01.2023.
//
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> acc{};

        auto findResult = acc.end();

        for (int i = 0; i < nums.size(); ++i) {
            if (acc.find(nums[i]) != findResult) {
                return {i, acc[nums[i]]};
            } else {
                acc.insert({target - nums[i], i});
            }
        }

        return {-1, -1};
    }
};

Solution solution;

void testHelper(std::vector<int>& input,
                std::vector<int>& output,
                int target) {
    auto res = solution.twoSum(input, target);
    assert (std::equal(res.begin(), res.end(), output.begin(), output.end()));
}

void test1() {
    std::vector<int> input {2,7,11,15};
    std::vector<int> output {0,1};
    testHelper(input, output, 9);
}

void test2() {
    std::vector<int> input {3,2,4};
    std::vector<int> output {1,2};
    testHelper(input, output, 6);
}

void test3() {
    std::vector<int> input {3,3};
    std::vector<int> output {0,1};
    testHelper(input, output, 6);
}

int main() {
    test1();
    test2();
    test3();
}


