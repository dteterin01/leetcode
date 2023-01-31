#include <vector>
#include <iostream>

//
// Created by Danil on 01.02.2023.
//
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int stash = 0;
        for (auto i: nums) {
            stash ^= i;
        }

        return stash;
    }
};

int main() {
    std::vector<int> a{1, 1, 2, 2, 3};
    std::cout << Solution().singleNumber(a);
}