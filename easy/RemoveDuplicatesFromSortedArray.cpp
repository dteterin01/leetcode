#include <vector>

//
// Created by Danil on 30.01.2023.
//
class Solution {
public:
    int RemoveDuplicates(std::vector<int>& nums) {
        int left = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[left++] = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
            count++;
        }
        return count;
    }
};