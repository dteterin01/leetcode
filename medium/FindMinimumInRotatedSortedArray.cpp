#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
public:

    // 3,4,5,1,2
    // 7 0 1 2 3 4
    int findMin(std::vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (nums[mid] > nums[mid + 1])
                return mid + 1;

            if (nums[mid] < nums[mid - 1])
                return mid;

            if (nums[mid] < nums[r])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};