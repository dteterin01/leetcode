#include <vector>
#include <cassert>

//
// Created by Danil on 25.08.2023.
//
class Solution {
public:

    int removeElement(std::vector<int>& nums, int val) {
        int lastNonElementIdx = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[lastNonElementIdx++] = nums[i];
            }
        }
        return lastNonElementIdx;
    }
};

int main() {
    std::vector<int> a {0,1,2,2,3,0,4,2};
    Solution solution;
    int res = solution.removeElement(a, 2);

    assert (5 == res);
};
