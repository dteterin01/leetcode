#include <vector>
#include <cassert>

//
// Created by Danil on 25.08.2023.
//
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int idx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (idx < 2 || num > nums[idx - 2]) {
                nums[idx++] = num;
            }
        }
    }
};

int main() {
    std::vector<int> a {1,2,2,2,3,3,5};
    Solution solution;
    int idx = solution.removeDuplicates(a);

    std::vector<int> res {1, 2, 2, 3, 3, 5};
    assert (std::equal(a.begin(), a.begin() + idx, res.begin(), res.end()) == true);
};
