#include <vector>

//
// Created by Danil on 31.08.2023.
//
class Solution {
private:
    static double binarySearchMedian(std::vector<int>& a, std::vector<int>& b, int needToFindIdx)
    {
        int aSize = a.size(), aStart = 0, aEnd = aSize - 1;
        int bSize = b.size(), bStart = 0, bEnd = bSize - 1;

        while (aStart <= aEnd && bStart <= bEnd)
        {
            int aMid = (aStart + aEnd) / 2, bMid = (bStart + bEnd) / 2;
            int aVal = a[aMid], bVal = b[bMid];

            if (aMid + bMid < needToFindIdx)
            {
                if (aVal > bVal) bStart = bMid + 1;
                else aStart = aMid + 1;
            }
            else
            {
                if (aVal > bVal) aEnd = aMid - 1;
                else bEnd = bMid - 1;
            }
        }

        if (aStart > aEnd)
            return b[needToFindIdx - aStart];
        else
            return a[needToFindIdx - bStart];
    }

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int mergedSize = nums1.size() + nums2.size();
        return (mergedSize) % 2 ?
            binarySearchMedian(nums1, nums2, mergedSize / 2) :
            (binarySearchMedian(nums1, nums2, mergedSize / 2) + binarySearchMedian(nums1, nums2, mergedSize / 2 - 1)) / 2;
    }

};