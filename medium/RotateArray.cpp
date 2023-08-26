#include <vector>
#include <cassert>

//
// Created by Danil on 26.08.2023.
// 1,2,3,4,5,6,7
// 7 6 5 4 3 2 1
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());

        std::reverse(nums.begin(), nums.begin() + k);

        std::reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    std::vector<int> a {1,2,2,2,3,3,5};
    Solution solution;
    solution.rotate(a, 3);

    std::vector<int> res {1, 2, 2, 3, 3, 5};
    assert (std::equal(a.begin(), a.begin(), res.begin(), res.end()) == true);
};