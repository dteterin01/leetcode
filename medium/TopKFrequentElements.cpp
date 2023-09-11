#include <vector>
#include <map>
#include <queue>

//
// Created by Danil on 01.09.2023.
//
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::map<int, int> countNumbers;
        std::vector<int> res;

        for (auto num: nums)
        {
            countNumbers[num]++;
        }

        std::priority_queue<std::pair<int, int>> q;

        for (auto val: countNumbers)
        {
            q.push({val.second, val.first});
        }

        while (k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};