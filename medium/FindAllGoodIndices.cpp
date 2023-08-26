#include <vector>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:

    // 2,1,1,1,3,4,1
    // 2 3 4 5 8 12 13

    // [2,1,3,2,3]
    //  2,3,6,8,11
    // -2 -1 2 4 6

    std::vector<int> goodIndices(std::vector<int>& nums, int k) {
        int sum = 0;
        for (auto& num: nums) {
            sum += num;
        }

        return {};
    }
};