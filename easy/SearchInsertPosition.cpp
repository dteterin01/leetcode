#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int low = 0, high = nums.size(), mid;

        if(target > nums[high - 1])
        {
            return high;
        }
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }

            if(target < nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return  low;
    }
};