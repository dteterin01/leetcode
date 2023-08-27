#include <vector>
#include <climits>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:

public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        int lIdx = -1, fIdx = -1, diffB, diffA, minDist = INT_MAX, maxDist = -1;
        int idx = 1;
        while (head->next != nullptr && head->next->next != nullptr)
        {
            diffB = head->val - head->next->val;
            diffA = head->next->next->val - head->next->val;
            if ((diffB != 0 && diffA != 0) && (diffA >> 31) == (diffB >> 31))
            {
                if (lIdx == -1)
                {
                    lIdx = idx;

                }
                else
                {
                    minDist = std::min(idx - fIdx, minDist);
                    maxDist = idx - lIdx;
                }
                fIdx = idx;
            }
            head = head->next;
            idx++;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        return {minDist, maxDist};
    }
};

int main() {
//    Solution().nodesBetweenCriticalPoints(
//            new ListNode(5,
//                         new ListNode(3,
//                                      new ListNode(1,
//                                                   new ListNode(2,
//                                                                new ListNode(5,
//                                                                             new ListNode(1,
//                                                                                          new ListNode(2, nullptr))))))));
}