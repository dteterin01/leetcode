#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
public:

    // 4,5,6,7,0,1,2
    //
    int findPeakElement(std::vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};