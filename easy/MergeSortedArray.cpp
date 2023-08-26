//
// Created by Danil on 25.08.2023.
//


#include <vector>
#include <cassert>

class Solution {
public:

    // 1 2 0 1 2 0
    // 1 2 1 2 0 0
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        m--;
        n--;
        int idx = nums1.size() - 1;
        while (n >= 0) {
            if (m >= 0 && nums1[m] > nums2[n]) {
                nums1[idx--] = nums1[m--];
            } else {
                nums1[idx--] = nums2[n--];
            }
        }
    }
};

int main() {
    std::vector<int> a {1,2,3,0,0,0};

    std::vector<int> b {2,5,6};
    Solution solution;
    solution.merge(a, 3, b, 3);
    b.begin()

    std::vector<int> res {1, 2, 2, 3, 5, 6};
    assert (std::equal(a.begin(), a.end(), res.begin(), res.end()) == true);
};
