#include <vector>
#include <iostream>

//
// Created by Danil on 30.01.2023.
//

//[7,1,5,3,6,4]
class Solution {
public:
    int MaxProfit(std::vector<int>& prices) {
        auto profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};