#include <vector>
#include <map>
#include <cmath>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    //
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::vector<int> pre(k);
        pre[0]=1;

        int ans=0, prefixSum=0;
        for(int x : nums){
            prefixSum += x;
            if (prefixSum < 0) {
                prefixSum += ceil(abs(prefixSum)*1.0/k)*k;
            }
            prefixSum %= k;
            ans += pre[prefixSum];
            pre[prefixSum] += 1;
        }
        return ans;
    }
};

int main() {
//    std::vector<int> a {4,5,0,-2,-3,1};
//    Solution solution;
//    int res = solution.subarraysDivByK(a, 5);
//    std::cout << res;

    std::vector<int> a {2,-2,2,-12};
    Solution solution;
    int res = solution.subarraysDivByK(a, 6);
    std::cout << res;
};
