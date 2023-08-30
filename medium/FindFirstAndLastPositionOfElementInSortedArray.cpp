#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
private:
    static int lowerBound(std::vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int startPos = lowerBound(nums, low, high, target);
        int lastPos = lowerBound(nums, low, high, target + 1);
        if (startPos <= high && nums[startPos] == target)
            return {startPos, lastPos};
        return {-1, -1};
    }
};