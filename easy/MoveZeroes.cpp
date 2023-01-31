//
// Created by Danil on 19.01.2023.
//
#include <vector>
#include <cassert>

class Solution {
public:

    // 1 2 0 1 2 0
    // 1 2 1 2 0 0
    void moveZeroes(std::vector<int>& nums) {
        int needToSwap = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[needToSwap]);
                needToSwap++;
            }
        }
    }
};

int main() {
    std::vector<int> a {12, 0, 1, 2, 0};
    Solution solution;
    solution.moveZeroes(a);

    std::vector<int> b {12, 1, 2, 0, 0};
    assert (std::equal(a.begin(), a.end(), b.begin(), b.end()) == true);
};

