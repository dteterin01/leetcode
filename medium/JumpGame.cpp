#include <vector>

//
// Created by Danil on 26.08.2023.
// [2,3,1,1,4]
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxJump = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxJump) {
                return false;
            }

            maxJump = std::max(maxJump, nums[i] + i);
        }
        return true;
    }
};