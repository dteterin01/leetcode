#include <string>
#include <vector>
#include <optional>
#include <sstream>
#include <iostream>

//
// Created by Danil on 20.01.2023.
//
class Solution {
private:

    //[0,1,2,4,5,7]
    //["0->2","4->5","7"]
    static std::string concat(std::pair<int, int>&& pair) {
        if (pair.first == pair.second) return std::to_string(pair.first);

        std::stringstream concatStream;
        (concatStream << pair.first << "->" << pair.second);
        return concatStream.str();
    }

public:

    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> res;
        for (auto l = 0; l < res.size() - 1; l++) {
            int r = l;
            while (r + 1 != res.size() && nums[r + 1] == nums[r] + 1) r++;
            res.push_back(concat(std::move(std::make_pair(nums[l], nums[r]))));
        }


        return res;
    }
};