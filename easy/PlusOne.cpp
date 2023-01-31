#include <vector>
#include <iostream>

//
// Created by Danil on 01.02.2023.
//
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int lastNumber = 1;
        for (std::size_t i = digits.size() - 1; i < UINT_MAX; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main() {
    std::vector<int> in {9, 9, 9, 9};
    auto res = Solution().plusOne(in);

    std::for_each(res.begin(), res.end(), [] (int x) {
       std::cout << x << " ";
    });
}