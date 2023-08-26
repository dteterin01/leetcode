#include <vector>

//
// Created by Danil on 26.08.2023.
// 7,1,5,3,6,4
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int size = prices.size(), buyPrice = prices[0], summaryProfit = 0;
        for (int i = 1; i < size; ++i) {
            if (prices[i] <= buyPrice) {
                buyPrice = prices[i];
            } else {
                summaryProfit += prices[i] - buyPrice;
                buyPrice = prices[i];
            }

        }
        return summaryProfit;
    }
};