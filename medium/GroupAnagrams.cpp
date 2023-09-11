#include <vector>
#include <string>
#include <map>

//
// Created by Danil on 01.09.2023.
//
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::map<std::string, std::vector<std::string>> map;

        for (auto str: strs)
        {
            std::string x = str;
            std::sort(str.begin(), str.end());
            map[str].push_back(x);
        }

        std::vector<std::vector<std::string>> res(map.size());

        for (auto& pair: map)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};