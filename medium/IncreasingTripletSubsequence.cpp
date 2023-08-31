#include <vector>
#include <climits>

//
// Created by Danil on 31.08.2023.
//
class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums)
    {
        int* res = new int[3];
        for (int i = 0; i < 3; ++i) {
            res[i] = INT_MAX;
        }

        int tmpIdx = 0, size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (nums[i] <= res[j]) {
                    res[j] = nums[i];
                    tmpIdx = std::max(tmpIdx, j);
                    break;
                }
            }

            if (tmpIdx == 2)
                return true;
        }

        return false;
    }
};

int main()
{
    std::vector<int> a {2,1,5,0,4,6};
    Solution().increasingTriplet(a);
    return 0;
}