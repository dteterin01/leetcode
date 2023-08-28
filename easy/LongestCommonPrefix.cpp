#include <string>
#include <vector>

//
// Created by Danil on 28.08.2023.
//
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string result;
        size_t maxPotentialSize = strs[0].size();
        std::string& tmp = strs[0];

        char tmpSymbol;
        for (size_t i = 0; i < maxPotentialSize; ++i)
        {
            tmpSymbol = tmp[i];
            for (std::string& str: strs)
            {
                if (i >= str.length() || tmpSymbol != str[i])
                {
                    return result;
                }
            }
            result += tmpSymbol;
        }
        return result;
    }
};