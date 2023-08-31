#include <vector>

//
// Created by Danil on 31.08.2023.
//
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp;
        int sizeNums = nums.size(), ans = 0;
        dp.push_back(nums[0]);

        for (int i = 1; i < sizeNums; ++i)
        {
            if (nums[i] > dp.back())
            {
                ans++;
                dp.push_back(nums[i]);
            }
            else
            {
                int idx = std::lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return ans + 1;
    }
};

int main() {
    std::vector<int> nums {10,9,2,5,3,7,101,18};
    Solution().lengthOfLIS(nums);
}
