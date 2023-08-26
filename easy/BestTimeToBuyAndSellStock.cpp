#include <vector>
#include <climits>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//

// 7,1,5,3,6,4
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int tmpProfit = -1;
        int buyPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            tmpProfit = buyPrice - prices[i];
            if (tmpProfit < 0) {
                buyPrice = prices[i];
            } else {
                std::cout << tmpProfit << " " << maxProfit << " " << buyPrice << " " << i << std::endl;
                maxProfit = std::max(tmpProfit, maxProfit);
            }
        }
        return maxProfit;
    }
};