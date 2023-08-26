#include <vector>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int maxJump = 0, prevJump = 0, countJumps = 0;
        for (int i = 0; i < nums.size(); ++i) {

            maxJump = std::max(maxJump, nums[i] + i);

            if (i == prevJump) {
                prevJump = maxJump;
                countJumps++;
            }
        }
        return countJumps;
    }
};