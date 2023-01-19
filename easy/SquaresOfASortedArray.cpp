#include <vector>

//
// Created by Danil on 19.01.2023.
//
class Solution {
public:
    //[-4,-1,0,3,10]
    // 16 100
    std::vector<int> SortedSquares(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int nextPos = r;

        std::vector<int> res(nums.size());
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                res[nextPos] = nums[l] * nums[l];
                l++;
            } else {
                res[nextPos] = nums[r] * nums[r];
                r--;
            }
            nextPos--;
        }

        return res;
    }
};
