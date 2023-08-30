#include <vector>

//
// Created by Danil on 31.08.2023.
//
class Solution {
private:
    static double binarySearchMedian(std::vector<int>& nums1, std::vector<int>& nums2, int needToFindIdx)
    {
        int aSize = nums1.size(), aStart = 0, aEnd = aSize - 1;
        int bSize = nums2.size(), bStart = 0, bEnd = bSize - 1;

        while (true)
        {
            if (aStart > aEnd)
                return nums2[needToFindIdx - aStart];

            if (bStart > bEnd)
                return nums1[needToFindIdx - bStart];

            int aMid = (aStart + aEnd) / 2, bMid = (bStart + bEnd) / 2;
            int aVal = nums1[aMid], bVal = nums2[bMid];

            if (aMid + bMid < needToFindIdx)
            {
                if (aVal > bVal) aStart = aMid + 1;
                else bStart = bMid + 1;
            }
            else
            {
                if (aVal > bVal) aEnd = aMid - 1;
                else bEnd = bMid - 1;
            }
        }
    }

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int aSize = nums1.size(), bSize = nums2.size();
        int mergeSize = aSize + bSize;
        if (mergeSize % 2)
        {
            return binarySearchMedian(nums1, nums2, mergeSize/2);
        }
        else
        {
            return (binarySearchMedian(nums1, nums2, mergeSize/2) + binarySearchMedian(nums1, nums2, mergeSize/2 - 1)) / 2;
        }
    }

};