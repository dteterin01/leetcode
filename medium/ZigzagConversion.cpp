#include <string>
#include <sstream>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1) return s;
        std::string res;

        int stepSize = numRows * 2 - 2, median = stepSize, size = s.size();
        for (int i = 0; i < numRows; ++i)
        {
            bool isNeedToAddMedianNumber = (median != 0 && median != stepSize);
            for (int j = i; j < size; j += stepSize)
            {
                res.push_back(s[j]);

                if (isNeedToAddMedianNumber && j + median < size)
                {
                    res.push_back(s[j + median]);
                }
            }
            median -= 2;
        }
        return res;
    }
};

int main() {
    auto res = Solution().convert("A", 1);
    std::cout << res << "\n";
    std::cout << "A";
}