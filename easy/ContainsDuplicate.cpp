//
// Created by Danil on 01.02.2023.
//

#include <vector>
#include <set>
#include <iostream>

class Solution {
public:
    // [1,2,3,1]
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> unique;

        for (auto i: nums) {
            if (!unique.insert(i).second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> a {1, 2, 3, 4};
    std::cout << Solution().containsDuplicate(a);
}