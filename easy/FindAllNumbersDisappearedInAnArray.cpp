#include <vector>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    // [4,3,2,7,8,2,3,1]
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        while (j < size) {
            int pos = nums[j] - 1;
            if ()
            std::swap(nums[j], nums[pos]);
        }

        std::vector<int> result;

        for (int i = 1; i <= size; ++i) {
            if (nums[i - 1] != i) {
                result.push_back(i);
            }
        }
        return result;
    }
};