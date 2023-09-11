#include <vector>

//
// Created by Danil on 01.09.2023.
//
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int size = nums.size();
        std::vector<int> prefixMul(nums.size());

        prefixMul[0] = 1;
        for (int i = 1; i < size; ++i)
        {
            prefixMul[i] = nums[i - 1] * prefixMul[i - 1];
        }

        int tmpMul = 1;
        for (int i = size - 1; i >= 0; --i)
        {
            prefixMul[i] *= tmpMul;
            tmpMul *= nums[i];
        }

        return prefixMul;
    }
};