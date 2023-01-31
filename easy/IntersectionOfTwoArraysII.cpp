#include <vector>
#include <set>
#include <iostream>

//
// Created by Danil on 01.02.2023.
//
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                nums1[k++] = nums1[i++];
                ++j;
            }
        }
        return { begin(nums1), begin(nums1) + k };
    }
};

int main() {
    std::vector<int> a{1, 1, 2, 2, 3};
    std::vector<int> b{2, 2};

    auto res = Solution().intersect(a, b);
    std::for_each(res.begin(), res.end(), [] (int x) {
        std::cout << x << " ";
    });
}