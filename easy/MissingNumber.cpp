#include <vector>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = (1 + nums.size()) * nums.size() / 2, tmpSum = 0;
        for (auto & num: nums) {
            tmpSum += sum;
        }
        return sum - tmpSum;
    }
};