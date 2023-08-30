#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
public:

    //4,5,6,7,0,1,2
    //0,1,2,4,5,6,7
    //6,7,0,1,2,4,5
    int search(std::vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;


            if (nums[mid] <= nums[r])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (nums[mid] > target && target >= nums[l])
                    r = mid + 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};