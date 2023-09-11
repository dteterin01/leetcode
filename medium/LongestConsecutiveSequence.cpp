#include <vector>
#include <map>
#include <unordered_set>

//
// Created by Danil on 01.09.2023.
//
class Solution {
public:
    // [100,4,200,1,3,2]
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> set;
        set.insert(nums.begin(), nums.end());

        int longestPath = 0;
        for (auto num: nums)
        {
            if (set.find(num - 1) != set.end()) continue;

            int tmpPath;
            for (int i = num + 1; set.contains(i); ++i)
            {
                tmpPath++;
            }

            longestPath = std::max(longestPath, tmpPath);
        }

        return longestPath;
    }
};