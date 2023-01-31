#include <vector>
#include <iostream>

//
// Created by Danil on 30.01.2023.
//
class Solution {
public:
    // 1 2 3 4 5 6 7 -> 7 6 5 4 3 2 1
    // 5 6 7 1 2 3 4

    // [7,1,2,3,4,5,6] -> 6 5 4 3 2 1 7
    // [5,6,7,1,2,3,4] k = 3 [5 6 7 1 2 3 4]
    // [4,5,6,7,1,2,3] k = 4 [4 5 6 7 1 2 3]
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        swap(nums, 0, nums.size() - 1);
        print(nums);
        swap(nums, 0, k);
        print(nums);
        swap(nums, k, nums.size() - 1);
        print(nums);
    }

private:
    static void print(std::vector<int>& nums) {
        std::cout << std::endl;
        for (auto i: nums) {
            std::cout << i << " ";
        }
    }

    static void swap(std::vector<int>& nums, int left, int right) {
        while (left < right) {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};